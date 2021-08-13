//
// Created by 潘一华 on 2021/8/12.
//

#include "RabbitMq.h"
#include <uv.h>
#include <amqpcpp.h>
#include <amqpcpp/libuv.h>
#include <util/tc_config.h>
#include <util/tc_common.h>
#include <servant/RemoteLogger.h>


namespace MqName {
    namespace Exchange{
        namespace LoginServer {
            const string Name = "LoginServer";
            const string KeySuccess = "Success";
        }
        namespace GateWay{
            const string Name = "GateWay";
        }
    }

    namespace Queue{
        namespace GateWay{
            const string LoginSuccess = "LoginSuccessForGateWay";
        }
    }
}

using namespace MqName;

class MqHandler : public AMQP::LibUvHandler
{
public:
    MqHandler(uv_loop_t *loop) : AMQP::LibUvHandler(loop) {}
public:
    virtual void onError(AMQP::TcpConnection *connection, const char *message) override
    {
        TLOG_ERROR( "handle ERROR. message:" << message << std::endl);
    }
    virtual void onConnected(AMQP::TcpConnection *connection) override
    {
        TLOG_INFO( "rabbit mq handle connected. " << std::endl);
    }
    virtual void onLost(AMQP::TcpConnection *connection)
    {
        TLOG_ERROR( "rabbit mq handle nost connection. " << std::endl);
    }
};



bool RabbitMq::init(const std::string& configPath) {
    tars::TC_Config conf;
    conf.parseFile(configPath);
    m_uri = tars::TC_Common::trim(conf.get("/main/rabbitMq<uri>", ""));
    if(m_uri.empty())
        return false;
    return true;
}

void RabbitMq::publish(const std::string& routingKey, const std::string& body) {
    m_channel->publish(m_exchange, routingKey, body);
}

void RabbitMq::run() {
    if(m_channel != nullptr)
    {
        TLOG_ERROR("run again" << endl);
        return;
    }

    auto *loop = uv_default_loop();
    MqHandler handler(loop);
    TLOG_INFO("rabbitMq connect to:" << m_uri << endl);
    AMQP::TcpConnection connection(&handler, AMQP::Address(m_uri));
    AMQP::TcpChannel channel(&connection);
    m_channel = &channel;
    m_channel->onError(
    [](const char *message)
    {
        TLOG_ERROR( "channel error ERROR. message:" << message << std::endl);
    });

    this->deploy();

    uv_run(loop, UV_RUN_DEFAULT);

    //连接断开会走到这里
    m_channel = nullptr;
    TLOG_ERROR("mq thread loop over" << endl);
}

RabbitMq::RabbitMq()
{
    m_channel = nullptr;
}

RabbitMq::~RabbitMq()
{
}

void RabbitMq::deploy()
{
    m_channel->declareQueue(Queue::GateWay::LoginSuccess, AMQP::durable).onSuccess(
    [](const std::string &name, uint32_t messagecount, uint32_t consumercount)
    {
        TLOG_INFO( "declared queue " << name << std::endl);
    });
    m_channel->bindQueue(Exchange::LoginServer::Name, Queue::GateWay::LoginSuccess, Exchange::LoginServer::KeySuccess)
    .onSuccess([]()
    {
        TLOG_INFO( "bind queue ok" << std::endl);
    });

    m_exchange = Exchange::GateWay::Name;

    m_channel->consume(Queue::GateWay::LoginSuccess).onMessage(
            [](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered)
            {
                TLOG_INFO( message.routingkey() << " " << message.body() << endl);
            });

}
