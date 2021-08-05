//
// Created by 潘一华 on 2021/7/30.
//

#ifndef PROXY_SERVER_WEBSOCKET_ADPT_H
#define PROXY_SERVER_WEBSOCKET_ADPT_H

#include "util/tc_socket.h"
#include "servant/Application.h"


TC_NetWorkBuffer::PACKET_TYPE parseWebSocket(TC_NetWorkBuffer&in, vector<char> &out);

void buildWSFrame(const vector<char> &data, vector<char> &frame);

void buildWSFrame(const char* buff, uint32_t len, vector<char> &frame);

void makeHandshakeRsp(const TC_HttpRequest& request, TC_HttpResponse& response);

inline void wsSendResponse(tars::TarsCurrentPtr current, const char* buff, uint32_t len)
{
    vector<char> frame;
    buildWSFrame(buff, len, frame);
    current->sendResponse(&frame[0], frame.size());
}


#endif //PROXY_SERVER_WEBSOCKET_ADPT_H

