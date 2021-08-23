//
// Created by 潘一华 on 2021/8/17.
//

#ifndef PROXY_SERVER_STATEIDMGR_H
#define PROXY_SERVER_STATEIDMGR_H
#include <string>
#include <map>
#include <mutex>

class StateIdMgr
{
public:
    static StateIdMgr* getInstance()
    {
        static StateIdMgr mgr;
        return &mgr;
    }
    void addStateId(const std::string& stateId, const std::string& endpoint);
    const std::string getEndpoint(const std::string& stateId);
private:
    StateIdMgr(){}
    std::map<std::string, std::string> m_room;
    std::mutex	m_stateMutex;
};

#endif //PROXY_SERVER_STATEIDMGR_H
