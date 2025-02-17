// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 2.4.13.
// **********************************************************************

#ifndef __FLOWCONTROL_H_
#define __FLOWCONTROL_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
#include "tup/TarsJson.h"
using namespace std;
#include "servant/ServantProxy.h"
#include "servant/Servant.h"


namespace Base
{

    /* callback of async proxy for client */
    class FlowControlPrxCallback: public tars::ServantProxyCallback
    {
    public:
        virtual ~FlowControlPrxCallback(){}
        virtual void callback_getGWDB(tars::Int32 ret,  const map<std::string, std::string>& dbConf)
        { throw std::runtime_error("callback_getGWDB() override incorrect."); }
        virtual void callback_getGWDB_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_getGWDB_exception() override incorrect."); }

        virtual void callback_report(tars::Int32 ret)
        { throw std::runtime_error("callback_report() override incorrect."); }
        virtual void callback_report_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_report_exception() override incorrect."); }

    public:
        virtual const map<std::string, std::string> & getResponseContext() const
        {
            CallbackThreadData * pCbtd = CallbackThreadData::getData();
            assert(pCbtd != NULL);

            if(!pCbtd->getContextValid())
            {
                throw TC_Exception("cann't get response context");
            }
            return pCbtd->getResponseContext();
        }

    public:
        virtual int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __FlowControl_all[]=
            {
                "getGWDB",
                "report"
            };
            pair<string*, string*> r = equal_range(__FlowControl_all, __FlowControl_all+2, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __FlowControl_all)
            {
                case 0:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_getGWDB_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    map<std::string, std::string> dbConf;
                    _is.read(dbConf, 1, true);
                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(msg->response->context);

                    callback_getGWDB(_ret, dbConf);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_report_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(msg->response->context);

                    callback_report(_ret);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<FlowControlPrxCallback> FlowControlPrxCallbackPtr;

    /* callback of coroutine async proxy for client */
    class FlowControlCoroPrxCallback: public FlowControlPrxCallback
    {
    public:
        virtual ~FlowControlCoroPrxCallback(){}
    public:
        virtual const map<std::string, std::string> & getResponseContext() const { return _mRspContext; }

        virtual void setResponseContext(const map<std::string, std::string> &mContext) { _mRspContext = mContext; }

    public:
        int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __FlowControl_all[]=
            {
                "getGWDB",
                "report"
            };

            pair<string*, string*> r = equal_range(__FlowControl_all, __FlowControl_all+2, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __FlowControl_all)
            {
                case 0:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_getGWDB_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        map<std::string, std::string> dbConf;
                        _is.read(dbConf, 1, true);
                        setResponseContext(msg->response->context);

                        callback_getGWDB(_ret, dbConf);

                    }
                    catch(std::exception &ex)
                    {
                        callback_getGWDB_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_getGWDB_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_report_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        setResponseContext(msg->response->context);

                        callback_report(_ret);

                    }
                    catch(std::exception &ex)
                    {
                        callback_report_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_report_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    protected:
        map<std::string, std::string> _mRspContext;
    };
    typedef tars::TC_AutoPtr<FlowControlCoroPrxCallback> FlowControlCoroPrxCallbackPtr;

    /* proxy for client */
    class FlowControlProxy : public tars::ServantProxy
    {
    public:
        typedef map<string, string> TARS_CONTEXT;
        tars::Int32 getGWDB(map<std::string, std::string> &dbConf,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(dbConf, 1);
            std::map<string, string> _mStatus;
            shared_ptr<tars::ResponsePacket> rep = tars_invoke(tars::TARSNORMAL,"getGWDB", _os, context, _mStatus);
            if(pResponseContext)
            {
                pResponseContext->swap(rep->context);
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep->sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            _is.read(dbConf, 1, true);
            return _ret;
        }

        void async_getGWDB(FlowControlPrxCallbackPtr callback,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"getGWDB", _os, context, _mStatus, callback);
        }
        
        void coro_getGWDB(FlowControlCoroPrxCallbackPtr callback,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"getGWDB", _os, context, _mStatus, callback, true);
        }

        tars::Int32 report(const map<std::string, tars::Int32> & flow,const std::string & ip,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(flow, 1);
            _os.write(ip, 2);
            std::map<string, string> _mStatus;
            shared_ptr<tars::ResponsePacket> rep = tars_invoke(tars::TARSNORMAL,"report", _os, context, _mStatus);
            if(pResponseContext)
            {
                pResponseContext->swap(rep->context);
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep->sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            return _ret;
        }

        void async_report(FlowControlPrxCallbackPtr callback,const map<std::string, tars::Int32> &flow,const std::string &ip,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(flow, 1);
            _os.write(ip, 2);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"report", _os, context, _mStatus, callback);
        }
        
        void coro_report(FlowControlCoroPrxCallbackPtr callback,const map<std::string, tars::Int32> &flow,const std::string &ip,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(flow, 1);
            _os.write(ip, 2);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"report", _os, context, _mStatus, callback, true);
        }

        FlowControlProxy* tars_hash(int64_t key)
        {
            return (FlowControlProxy*)ServantProxy::tars_hash(key);
        }

        FlowControlProxy* tars_consistent_hash(int64_t key)
        {
            return (FlowControlProxy*)ServantProxy::tars_consistent_hash(key);
        }

        FlowControlProxy* tars_set_timeout(int msecond)
        {
            return (FlowControlProxy*)ServantProxy::tars_set_timeout(msecond);
        }

        static const char* tars_prxname() { return "FlowControlProxy"; }
    };
    typedef tars::TC_AutoPtr<FlowControlProxy> FlowControlPrx;

    /* servant for server */
    class FlowControl : public tars::Servant
    {
    public:
        virtual ~FlowControl(){}
        virtual tars::Int32 getGWDB(map<std::string, std::string> &dbConf,tars::TarsCurrentPtr current) = 0;
        static void async_response_getGWDB(tars::TarsCurrentPtr current, tars::Int32 _ret, const map<std::string, std::string> &dbConf)
        {
            if (current->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                tarsAttr.setVersion(current->getRequestVersion());
                tarsAttr.put("", _ret);
                tarsAttr.put("tars_ret", _ret);
                tarsAttr.put("dbConf", dbConf);

                vector<char> sTupResponseBuffer;
                tarsAttr.encode(sTupResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
            }
            else if (current->getRequestVersion() == JSONVERSION)
            {
                tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                _p->value["dbConf"] = tars::JsonOutput::writeJson(dbConf);
                _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                vector<char> sJsonResponseBuffer;
                tars::TC_Json::writeValue(_p, sJsonResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sJsonResponseBuffer);
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                _os.write(dbConf, 1);

                current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
            }
        }

        virtual tars::Int32 report(const map<std::string, tars::Int32> & flow,const std::string & ip,tars::TarsCurrentPtr current) = 0;
        static void async_response_report(tars::TarsCurrentPtr current, tars::Int32 _ret)
        {
            if (current->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                tarsAttr.setVersion(current->getRequestVersion());
                tarsAttr.put("", _ret);
                tarsAttr.put("tars_ret", _ret);

                vector<char> sTupResponseBuffer;
                tarsAttr.encode(sTupResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
            }
            else if (current->getRequestVersion() == JSONVERSION)
            {
                tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                vector<char> sJsonResponseBuffer;
                tars::TC_Json::writeValue(_p, sJsonResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sJsonResponseBuffer);
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriterVector> _os;
                _os.write(_ret, 0);

                current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
            }
        }

    public:
        int onDispatch(tars::TarsCurrentPtr _current, vector<char> &_sResponseBuffer)
        {
            static ::std::string __Base__FlowControl_all[]=
            {
                "getGWDB",
                "report"
            };

            pair<string*, string*> r = equal_range(__Base__FlowControl_all, __Base__FlowControl_all+2, _current->getFuncName());
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Base__FlowControl_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    map<std::string, std::string> dbConf;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                        tarsAttr.getByDefault("dbConf", dbConf, dbConf);
                    }
                    else if (_current->getRequestVersion() == JSONVERSION)
                    {
                        tars::JsonValueObjPtr _jsonPtr = tars::JsonValueObjPtr::dynamicCast(tars::TC_Json::getValue(_current->getRequestBuffer()));
                        tars::JsonInput::readJson(dbConf, _jsonPtr->value["dbConf"], false);
                    }
                    else
                    {
                        _is.read(dbConf, 1, false);
                    }
                    tars::Int32 _ret = getGWDB(dbConf, _current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION)
                        {
                            UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                            tarsAttr.setVersion(_current->getRequestVersion());
                            tarsAttr.put("", _ret);
                            tarsAttr.put("tars_ret", _ret);
                            tarsAttr.put("dbConf", dbConf);
                            tarsAttr.encode(_sResponseBuffer);
                        }
                        else if (_current->getRequestVersion() == JSONVERSION)
                        {
                            tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                            _p->value["dbConf"] = tars::JsonOutput::writeJson(dbConf);
                            _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                            tars::TC_Json::writeValue(_p, _sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriterVector> _os;
                            _os.write(_ret, 0);
                            _os.write(dbConf, 1);
                            _os.swap(_sResponseBuffer);
                        }
                    }
                    return tars::TARSSERVERSUCCESS;

                }
                case 1:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    map<std::string, tars::Int32> flow;
                    std::string ip;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                        tarsAttr.get("flow", flow);
                        tarsAttr.get("ip", ip);
                    }
                    else if (_current->getRequestVersion() == JSONVERSION)
                    {
                        tars::JsonValueObjPtr _jsonPtr = tars::JsonValueObjPtr::dynamicCast(tars::TC_Json::getValue(_current->getRequestBuffer()));
                        tars::JsonInput::readJson(flow, _jsonPtr->value["flow"], true);
                        tars::JsonInput::readJson(ip, _jsonPtr->value["ip"], true);
                    }
                    else
                    {
                        _is.read(flow, 1, true);
                        _is.read(ip, 2, true);
                    }
                    tars::Int32 _ret = report(flow,ip, _current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION)
                        {
                            UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                            tarsAttr.setVersion(_current->getRequestVersion());
                            tarsAttr.put("", _ret);
                            tarsAttr.put("tars_ret", _ret);
                            tarsAttr.encode(_sResponseBuffer);
                        }
                        else if (_current->getRequestVersion() == JSONVERSION)
                        {
                            tars::JsonValueObjPtr _p = new tars::JsonValueObj();
                            _p->value["tars_ret"] = tars::JsonOutput::writeJson(_ret);
                            tars::TC_Json::writeValue(_p, _sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriterVector> _os;
                            _os.write(_ret, 0);
                            _os.swap(_sResponseBuffer);
                        }
                    }
                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }
    };


}



#endif
