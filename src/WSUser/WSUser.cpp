//
// Created by 潘一华 on 2021/7/30.
//

#include "WSUser.h"

#include <memory>


void WSUserMgr::addUser(tars::TarsCurrentPtr current, const std::string& ip)
{
    auto connectId = current->getUId();
    std::unique_lock<std::mutex> lock(m_userMutex);
    auto& user = m_user[connectId];
    if(!user){
        user = std::make_shared<WSUser>();
    }
    user->m_current = current;
    user->m_real_ip = ip;
}

void WSUserMgr::delUser(uint32_t connectId)
{
    std::unique_lock<std::mutex> lock(m_userMutex);
    m_user.erase(connectId);
}

bool WSUserMgr::isWS(uint32_t connectId)
{
    auto it = m_user.find(connectId);
    if(it != m_user.end())
        return true;
    return false;
}

WSUserPtr WSUserMgr::getUser(uint32_t connectId) {
    auto it = m_user.find(connectId);
    if(it != m_user.end())
        return it->second;
    return nullptr;
}



