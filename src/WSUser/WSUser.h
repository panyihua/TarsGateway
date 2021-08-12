//
// Created by 潘一华 on 2021/7/30.
//

#ifndef PROXY_SERVER_WSUSER_H
#define PROXY_SERVER_WSUSER_H

#include <map>
#include "websocket/websocket_adpt.h"
#include <mutex>
#include <cstdint>

//WebSocket user
class WSUser
{
public:
    WSUser()
    {
        m_uid = 0;
    }
    int64_t m_uid;

    tars::TarsCurrentPtr m_current;
    std::string m_real_ip;
};

class WSUserMgr
{
public:
    static void addUser(tars::TarsCurrentPtr, const std::string& ip);
    static void delUser(uint32_t connectId);
    static bool isWS(uint32_t connectId);
    static WSUser* getWS(uint32_t connectId);
private:
    static std::map<uint32_t, WSUser> m_user;
    static std::mutex	m_userMutex;
};

#endif //PROXY_SERVER_WSUSER_H
