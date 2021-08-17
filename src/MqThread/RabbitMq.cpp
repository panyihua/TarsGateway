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
#include "tarsdepend/LoginServer/loginMq.h"
#include "WSUser/WSUser.h"


namespace MqName {
    namespace Exchange{
        namespace LoginServer {
            const string Name = "LoginServer";
            const string KeySuccess = "Success";
        }
        namespace GateWay{
            const string Name = "GateWayServer";
            const string Key = "UidBindCid";
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
        TLOG_ERROR( "rabbit mq handle lost connection. " << std::endl);
    }
    virtual void onHeartbeat(AMQP::TcpConnection *connection) {
        connection->heartbeat();
    }
};



bool RabbitMq::init(const std::string& configPath) {
    tars::TC_Config conf;
    conf.parseFile(configPath);
    m_uri = tars::TC_Common::trim(conf.get("/main/rabbitMq<uri>", ""));

    return !m_uri.empty();
}

//todo 业务层调用，需要加锁
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
    [loop](const char *message)
    {
        uv_loop_close(loop);
        TLOG_ERROR( "channel error ERROR. message:" << message << std::endl);
    });

    this->deploy();

    uv_run(loop, UV_RUN_DEFAULT);
    uv_loop_close(loop);

    //连接断开会走到这里
    m_channel->close();
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
    m_channel->declareExchange(Exchange::LoginServer::Name, (AMQP::ExchangeType)1, AMQP::durable);

    m_channel->declareExchange(Exchange::GateWay::Name, (AMQP::ExchangeType)1, AMQP::durable);

    m_channel->bindQueue(Exchange::LoginServer::Name, Queue::GateWay::LoginSuccess, Exchange::LoginServer::KeySuccess)
    .onSuccess([]()
    {
        TLOG_INFO( "bind queue ok" << std::endl);
    });

    m_exchange = Exchange::GateWay::Name;

    int flag = 0;
    // flag |= AMQP::noack;
    m_channel->consume(Queue::GateWay::LoginSuccess, flag).onMessage(
            [this](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered)
            {

                TLOG_INFO("consume msg:" <<  message.routingkey() << " " << message.body() << endl);

                loginMqTars::UserLoginMsg msg;
                msg.readFromJsonString(message.body());

                auto user = WSUserMgr::getInstance()->getUser(msg.cid);
                if(user == nullptr) {
                    TLOG_ERROR("consume login message msg error. " << msg << endl);
                }
                else {
                    if (user->m_current->getBindAdapter()->getEndpoint().toString() == msg.gate){
                        user->setUid(msg.uid);
                        TLOG_INFO("bind user ok.   " << msg << endl);

                        this->publish(Exchange::GateWay::Key, message.body());

                    } else{
                        TLOG_INFO("bind user onther gate:   " << msg << endl);
                    }
                }
                this->m_channel->ack(deliveryTag);
            });

}
