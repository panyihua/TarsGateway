//
// Created by 潘一华 on 2021/8/12.
//

#ifndef PROXY_SERVER_RABBITMQ_H
#define PROXY_SERVER_RABBITMQ_H
#include <string>

namespace AMQP {
    struct TcpChannel;
}

class RabbitMq
{
public:
    RabbitMq();
    ~RabbitMq();
    void init(const std::string& configPath);
    void run();
    void deploy();
    void publish(const std::string& routingKey, const std::string& body);

private:
    std::string m_uri;

    AMQP::TcpChannel* m_channel;

    std::string m_exchange;
};


#endif //PROXY_SERVER_RABBITMQ_H
