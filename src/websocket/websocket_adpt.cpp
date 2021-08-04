//
// Created by 潘一华 on 2021/7/30.
//
#include "websocket_adpt.h"

#include <memory>
#include <string.h>
#include "servant/RemoteLogger.h"
#include "util/tc_http.h"


#include "websocket/3rd/websocket_parser/websocket_parser.h"
#include "websocket/3rd/websocket_parser/sha1.hpp"
#include "websocket/3rd/websocket_parser/base64.hpp"

static char const handshake_guid[] = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";

void makeHandshakeRsp(const TC_HttpRequest& request, TC_HttpResponse& response)
{
    std::string server_key = request.getHeader("Sec-WebSocket-Key");

    server_key.append(handshake_guid);

    unsigned char message_digest[20];
    sha1::calc(server_key.c_str(),server_key.length(),message_digest);
    server_key = base64_encode(message_digest,20);

    response.setHeader("Sec-WebSocket-Accept",server_key);
    response.setHeader("Upgrade", "websocket");
    response.setHeader("Connection","Upgrade");

    //response.setResponse(101, "ok", "sb, poor websocket");
    response.setStatus(101);
}



TC_NetWorkBuffer::PACKET_TYPE parseWebSocket(TC_NetWorkBuffer&in, vector<char> &out)
{
    websocket_parser parser;
    memset(&parser, 0, sizeof(parser));
    auto ret = websocket_parser_execute(&parser, NULL, in.mergeBuffers(), in.getBufferLength());
    auto c = (tars::TC_EpollServer::Connection*)in.getConnection();

    TLOG_DEBUG("connectId:" << c->getId() << " parseWebSocket ret:" << ret << " state:" << parser.state
                       << "offset" << parser.offset << " length:" << parser.length
                       << "flags:" << parser.flags << endl);

    if(ret == -1)
    {
        TLOG_DEBUG("connectId:" << c->getId() << " parseWebSocket parser less. " << endl);
        return TC_NetWorkBuffer::PACKET_LESS;
    }
    else if(ret > 0)
    {
        auto head = parser.offset;
        auto body = parser.length;
        auto b = in.getBufferPointer();
        if(b.second < head + body)
        {
            TLOG_DEBUG("connectId:" << c->getId() << " parseWebSocket parser less. head:" << head << " body:" << body << endl);
            return TC_NetWorkBuffer::PACKET_LESS;
        }

        in.moveHeader(head);
        in.getHeader(body, out);
        in.moveHeader(body);
        TLOG_DEBUG("connectId:" << c->getId() << " parseWebSocket parser ok. head:" << head << " body:" << body << endl);
        return TC_NetWorkBuffer::PACKET_FULL;
    }
    else {
        TLOG_ERROR("connectId:" << c->getId() << " parseWebSocket error:" << ret << parser.length << parser.state << endl);
        return TC_NetWorkBuffer::PACKET_ERR;
    }
}

void buildWSFrame(const vector<char> &data, vector<char> &frame)
{
    if(data.empty())
        return;

    auto len = websocket_calc_frame_size(websocket_flags(WS_OP_TEXT | WS_FINAL_FRAME), data.size());

    frame.clear();
    frame.resize(len, 0);

    websocket_build_frame(&frame[0], websocket_flags(WS_OP_BINARY | WS_FINAL_FRAME), NULL, &data[0], data.size());
}


/*
 *
#include "websocket/3rd/WebSocket/WebSocket.h"
void processHandShake(TC_NetWorkBuffer&in, vector<char> &out)
{

}

TC_NetWorkBuffer::PACKET_TYPE parseWebSocket(TC_NetWorkBuffer&in, vector<char> &out)
{
    getFrame()
}

void buildWSFrame(const vector<char> &data, vector<char> &frame);

void makeHandshakeRsp(const TC_HttpRequest& request, TC_HttpResponse& response);
*/
