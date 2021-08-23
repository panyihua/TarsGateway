//
// Created by 潘一华 on 2021/8/23.
//

#ifndef PROXY_SERVER_CIDPROXYIMP_H
#define PROXY_SERVER_CIDPROXYIMP_H

#include "servant/Application.h"

using namespace std;
using namespace tars;

class CidProxyImp : public tars::Servant
{
public:

    virtual int doRequest(tars::TarsCurrentPtr current, vector<char>& response);

    // virtual int onDispatch(tars::TarsCurrentPtr current, vector<char>& response);

    virtual void initialize() {};

    virtual void destroy() {};

    virtual ~CidProxyImp(){}

protected:
};


#endif //PROXY_SERVER_CIDPROXYIMP_H
