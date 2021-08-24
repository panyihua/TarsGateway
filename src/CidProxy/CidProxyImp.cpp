//
// Created by 潘一华 on 2021/8/23.
//

#include "CidProxyImp.h"
#include "WSUser/WSUser.h"

int CidProxyImp::doRequest(tars::TarsCurrentPtr current, vector<char>& response){

    current->setResponse(false);

    if(current->getRequestBuffer().size() < 4){
        TLOG_ERROR("tup buff len < 4 ERROR" << endl);
        return -1;
    }

    const char* buff = &current->getRequestBuffer()[0];
    uint32_t len = current->getRequestBuffer().size();

    //去掉4字节长度信息
    tars::TarsInputStream<BufferReader> is;
    is.setBuffer(buff + 4, len - 4);
    RequestPacket tupRequest;
    tupRequest.readFrom(is);
    auto cid = strtoul(tupRequest.context["cid"].c_str(), NULL, 10);
    TLOG_DEBUG("proxy cid:" << cid << " tup request:" << tupRequest << endl);

    auto ws = WSUserMgr::getInstance()->getUser(cid);
    if(ws){
        if(ws->m_current){
            wsSendResponse(ws->m_current, buff, len);
            TLOG_DEBUG("ws send size:" << current->getRequestBuffer().size() << endl);
        }
    }
    return 0;
}
