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
#include <time.h>


void threadMain()
{
    while(true)
    {
        auto b = RabbitMq::getInstance()->init(g_app.getConfFile());
        if(!b){
            break;
        }
        auto start = time(NULL);
        RabbitMq::getInstance()->run();
        auto end = time(NULL);
        auto s = 5 - (end - start);
        if (s < 0){
            s = 0;
        }

        auto t = std::chrono::seconds(s);
        TLOG_ERROR("rabbit mq reconnect. " << "sleep:" << s << endl);
        std::this_thread::sleep_for(t);
    }

    TLOG_ERROR("mq thread over" << endl);
}

int startMqThread()
{
    std::thread t(threadMain);
    t.detach();
    return 0;
}
