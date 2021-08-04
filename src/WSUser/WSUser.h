//
// Created by 潘一华 on 2021/7/30.
//

#ifndef PROXY_SERVER_WSUSER_H
#define PROXY_SERVER_WSUSER_H

#include <map>

//WebSocket user
class WSUser
{

};

class WSUserMgr
{
public:
    static void addUser(uint32_t connectId);
    static bool isWS(uint32_t connectId);
    static WSUser* getWS(uint32_t connectId);
private:
    static std::map<uint32_t, WSUser> m_user;
};

#endif //PROXY_SERVER_WSUSER_H
