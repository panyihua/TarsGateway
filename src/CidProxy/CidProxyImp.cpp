//
// Created by 潘一华 on 2021/8/23.
//

#include "CidProxyImp.h"
#include "WSUser/WSUser.h"

int CidProxyImp::doRequest(tars::TarsCurrentPtr current, vector<char>& response){

    current->setResponse(false);

    tars::TarsInputStream<BufferReader> is;
    is.setBuffer(&current->getRequestBuffer()[0], current->getRequestBuffer().size());
    RequestPacket tupRequest;
    tupRequest.readFrom(is);
    TLOG_DEBUG("tup request:" << tupRequest << endl);

    auto cid = strtoul(tupRequest.context["cid"].c_str(), NULL, 10);
    TLOG_DEBUG("proxy cid:" << cid << endl);
    auto ws = WSUserMgr::getInstance()->getUser(cid);
    if(ws){
        if(ws->m_current){
            ws->m_current->sendResponse(&current->getRequestBuffer()[0], current->getRequestBuffer().size());
        }
    }
    return 0;
}
