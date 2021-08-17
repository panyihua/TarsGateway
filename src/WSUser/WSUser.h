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
    void setUid(int64_t uid)
    {
        m_uid = uid;
    }
    int64_t m_uid;

    tars::TarsCurrentPtr m_current;
    std::string m_real_ip;
};

class WSUserMgr
{
public:
    static WSUserMgr* getInstance()
    {
        static WSUserMgr mgr;
        return &mgr;
    }
    void addUser(tars::TarsCurrentPtr, const std::string& ip);
    void delUser(uint32_t connectId);
    bool isWS(uint32_t connectId);
    WSUser* getUser(uint32_t connectId);
private:
    WSUserMgr(){}
    std::map<uint32_t, WSUser> m_user;
    std::mutex	m_userMutex;
};

#endif //PROXY_SERVER_WSUSER_H
