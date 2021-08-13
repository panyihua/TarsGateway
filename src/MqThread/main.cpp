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


void threadMain()
{
    while(true)
    {
        auto b = RabbitMq::getInstance()->init(g_app.getConfFile());
        if(!b){
            break;
        }
        RabbitMq::getInstance()->run();
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    TLOG_ERROR("mq thread over" << endl);
}

int startMqThread()
{
    std::thread t(threadMain);
    t.detach();
    return 0;
}
