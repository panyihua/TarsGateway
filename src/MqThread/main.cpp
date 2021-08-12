//
// Created by 潘一华 on 2021/8/9.
//

#include "main.h"
#include <uv.h>
#include <amqpcpp.h>
#include <amqpcpp/libuv.h>
#include <thread>
#include "MqThread/RabbitMq.h"
#include "GatewayServer.h"

extern GatewayServer g_app;

void threadMain()
{
    static RabbitMq g_mq;
    g_mq.init(g_app.getConfFile());
    g_mq.run();
}

int startMqThread()
{
    std::thread t(threadMain);
    t.detach();
    return 0;
}
