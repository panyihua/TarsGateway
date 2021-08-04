//
// Created by 潘一华 on 2021/7/30.
//

#include "WSUser.h"

std::map<uint32_t, WSUser> WSUserMgr:: m_user;

void WSUserMgr::addUser(uint32_t connectId)
{
    m_user[connectId];
}

bool WSUserMgr::isWS(uint32_t connectId)
{
    auto it = m_user.find(connectId);
    if(it != m_user.end())
        return true;
    return false;
}

WSUser *WSUserMgr::getWS(uint32_t connectId) {
    auto it = m_user.find(connectId);
    if(it != m_user.end())
        return &(it->second);
    return nullptr;
}

