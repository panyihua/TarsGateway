// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 2.4.13.
// **********************************************************************

#ifndef __ADMINS.AUTHS_H_
#define __ADMINS.AUTHS_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
#include "tup/TarsJson.h"
using namespace std;
#include "servant/ServantProxy.h"
#include "servant/Servant.h"


namespace authstars
{
    struct VerifyData : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "authstars.VerifyData";
        }
        static string MD5()
        {
            return "851eb7ded9ace1db742e88f4f1f495ba";
        }
        VerifyData()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            userid = 0;
            pass = true;
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(userid, 0);
            _os.write(pass, 1);
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(userid, 0, true);
            _is.read(pass, 1, true);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["userid"] = tars::JsonOutput::writeJson(userid);
            p->value["pass"] = tars::JsonOutput::writeJson(pass);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(userid,pObj->value["userid"], true);
            tars::JsonInput::readJson(pass,pObj->value["pass"], true);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(userid,"userid");
            _ds.display(pass,"pass");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(userid, true);
            _ds.displaySimple(pass, false);
            return _os;
        }
    public:
        tars::Int64 userid;
        tars::Bool pass;
    };
    inline bool operator==(const VerifyData&l, const VerifyData&r)
    {
        return l.userid == r.userid && l.pass == r.pass;
    }
    inline bool operator!=(const VerifyData&l, const VerifyData&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const VerifyData&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,VerifyData&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }

    struct PermissionVerifyReq : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "authstars.PermissionVerifyReq";
        }
        static string MD5()
        {
            return "c73c13678f156f762d622e8672930c1d";
        }
        PermissionVerifyReq()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            token = "";
            servantName = "";
            funcName = "";
            reqParam = "";
            remoteAddr = "";
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(token, 0);
            _os.write(servantName, 1);
            _os.write(funcName, 2);
            if (reqParam != "")
            {
                _os.write(reqParam, 3);
            }
            if (remoteAddr != "")
            {
                _os.write(remoteAddr, 4);
            }
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(token, 0, true);
            _is.read(servantName, 1, true);
            _is.read(funcName, 2, true);
            _is.read(reqParam, 3, false);
            _is.read(remoteAddr, 4, false);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["token"] = tars::JsonOutput::writeJson(token);
            p->value["servantName"] = tars::JsonOutput::writeJson(servantName);
            p->value["funcName"] = tars::JsonOutput::writeJson(funcName);
            p->value["reqParam"] = tars::JsonOutput::writeJson(reqParam);
            p->value["remoteAddr"] = tars::JsonOutput::writeJson(remoteAddr);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(token,pObj->value["token"], true);
            tars::JsonInput::readJson(servantName,pObj->value["servantName"], true);
            tars::JsonInput::readJson(funcName,pObj->value["funcName"], true);
            tars::JsonInput::readJson(reqParam,pObj->value["reqParam"], false);
            tars::JsonInput::readJson(remoteAddr,pObj->value["remoteAddr"], false);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(token,"token");
            _ds.display(servantName,"servantName");
            _ds.display(funcName,"funcName");
            _ds.display(reqParam,"reqParam");
            _ds.display(remoteAddr,"remoteAddr");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(token, true);
            _ds.displaySimple(servantName, true);
            _ds.displaySimple(funcName, true);
            _ds.displaySimple(reqParam, true);
            _ds.displaySimple(remoteAddr, false);
            return _os;
        }
    public:
        std::string token;
        std::string servantName;
        std::string funcName;
        std::string reqParam;
        std::string remoteAddr;
    };
    inline bool operator==(const PermissionVerifyReq&l, const PermissionVerifyReq&r)
    {
        return l.token == r.token && l.servantName == r.servantName && l.funcName == r.funcName && l.reqParam == r.reqParam && l.remoteAddr == r.remoteAddr;
    }
    inline bool operator!=(const PermissionVerifyReq&l, const PermissionVerifyReq&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const PermissionVerifyReq&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,PermissionVerifyReq&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }

    struct PermissionVerifyRsp : public tars::TarsStructBase
    {
    public:
        static string className()
        {
            return "authstars.PermissionVerifyRsp";
        }
        static string MD5()
        {
            return "bdc944a6c98ea2f1fd2675073280a773";
        }
        PermissionVerifyRsp()
        {
            resetDefautlt();
        }
        void resetDefautlt()
        {
            code = 0;
            message = "";
        }
        template<typename WriterT>
        void writeTo(tars::TarsOutputStream<WriterT>& _os) const
        {
            _os.write(code, 0);
            if (message != "")
            {
                _os.write(message, 1);
            }
            _os.write(data, 2);
        }
        template<typename ReaderT>
        void readFrom(tars::TarsInputStream<ReaderT>& _is)
        {
            resetDefautlt();
            _is.read(code, 0, true);
            _is.read(message, 1, false);
            _is.read(data, 2, false);
        }
        tars::JsonValueObjPtr writeToJson() const
        {
            tars::JsonValueObjPtr p = new tars::JsonValueObj();
            p->value["code"] = tars::JsonOutput::writeJson(code);
            p->value["message"] = tars::JsonOutput::writeJson(message);
            p->value["data"] = tars::JsonOutput::writeJson(data);
            return p;
        }
        string writeToJsonString() const
        {
            return tars::TC_Json::writeValue(writeToJson());
        }
        void readFromJson(const tars::JsonValuePtr & p, bool isRequire = true)
        {
            resetDefautlt();
            if(NULL == p.get() || p->getType() != tars::eJsonTypeObj)
            {
                char s[128];
                snprintf(s, sizeof(s), "read 'struct' type mismatch, get type: %d.", (p.get() ? p->getType() : 0));
                throw tars::TC_Json_Exception(s);
            }
            tars::JsonValueObjPtr pObj=tars::JsonValueObjPtr::dynamicCast(p);
            tars::JsonInput::readJson(code,pObj->value["code"], true);
            tars::JsonInput::readJson(message,pObj->value["message"], false);
            tars::JsonInput::readJson(data,pObj->value["data"], false);
        }
        void readFromJsonString(const string & str)
        {
            readFromJson(tars::TC_Json::getValue(str));
        }
        ostream& display(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.display(code,"code");
            _ds.display(message,"message");
            _ds.display(data,"data");
            return _os;
        }
        ostream& displaySimple(ostream& _os, int _level=0) const
        {
            tars::TarsDisplayer _ds(_os, _level);
            _ds.displaySimple(code, true);
            _ds.displaySimple(message, true);
            _ds.displaySimple(data, false);
            return _os;
        }
    public:
        tars::Int32 code;
        std::string message;
        authstars::VerifyData data;
    };
    inline bool operator==(const PermissionVerifyRsp&l, const PermissionVerifyRsp&r)
    {
        return l.code == r.code && l.message == r.message && l.data == r.data;
    }
    inline bool operator!=(const PermissionVerifyRsp&l, const PermissionVerifyRsp&r)
    {
        return !(l == r);
    }
    inline ostream& operator<<(ostream & os,const PermissionVerifyRsp&r)
    {
        os << r.writeToJsonString();
        return os;
    }
    inline istream& operator>>(istream& is,PermissionVerifyRsp&l)
    {
        std::istreambuf_iterator<char> eos;
        std::string s(std::istreambuf_iterator<char>(is), eos);
        l.readFromJsonString(s);
        return is;
    }


    /* callback of async proxy for client */
    class authsAPIPrxCallback: public tars::ServantProxyCallback
    {
    public:
        virtual ~authsAPIPrxCallback(){}
        virtual void callback_PermissionVerify(const authstars::PermissionVerifyRsp& ret)
        { throw std::runtime_error("callback_PermissionVerify() override incorrect."); }
        virtual void callback_PermissionVerify_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_PermissionVerify_exception() override incorrect."); }

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
            static ::std::string __authsAPI_all[]=
            {
                "PermissionVerify"
            };
            pair<string*, string*> r = equal_range(__authsAPI_all, __authsAPI_all+1, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __authsAPI_all)
            {
                case 0:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_PermissionVerify_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    authstars::PermissionVerifyRsp _ret;
                    _is.read(_ret, 0, true);

                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(msg->response->context);

                    callback_PermissionVerify(_ret);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<authsAPIPrxCallback> authsAPIPrxCallbackPtr;

    /* callback of coroutine async proxy for client */
    class authsAPICoroPrxCallback: public authsAPIPrxCallback
    {
    public:
        virtual ~authsAPICoroPrxCallback(){}
    public:
        virtual const map<std::string, std::string> & getResponseContext() const { return _mRspContext; }

        virtual void setResponseContext(const map<std::string, std::string> &mContext) { _mRspContext = mContext; }

    public:
        int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __authsAPI_all[]=
            {
                "PermissionVerify"
            };

            pair<string*, string*> r = equal_range(__authsAPI_all, __authsAPI_all+1, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __authsAPI_all)
            {
                case 0:
                {
                    if (msg->response->iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_PermissionVerify_exception(msg->response->iRet);

                        return msg->response->iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response->sBuffer);
                    try
                    {
                        authstars::PermissionVerifyRsp _ret;
                        _is.read(_ret, 0, true);

                        setResponseContext(msg->response->context);

                        callback_PermissionVerify(_ret);

                    }
                    catch(std::exception &ex)
                    {
                        callback_PermissionVerify_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_PermissionVerify_exception(tars::TARSCLIENTDECODEERR);

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
    typedef tars::TC_AutoPtr<authsAPICoroPrxCallback> authsAPICoroPrxCallbackPtr;

    /* proxy for client */
    class authsAPIProxy : public tars::ServantProxy
    {
    public:
        typedef map<string, string> TARS_CONTEXT;
        authstars::PermissionVerifyRsp PermissionVerify(const authstars::PermissionVerifyReq & req,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(req, 1);
            std::map<string, string> _mStatus;
            shared_ptr<tars::ResponsePacket> rep = tars_invoke(tars::TARSNORMAL,"PermissionVerify", _os, context, _mStatus);
            if(pResponseContext)
            {
                pResponseContext->swap(rep->context);
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep->sBuffer);
            authstars::PermissionVerifyRsp _ret;
            _is.read(_ret, 0, true);
            return _ret;
        }

        void async_PermissionVerify(authsAPIPrxCallbackPtr callback,const authstars::PermissionVerifyReq &req,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(req, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"PermissionVerify", _os, context, _mStatus, callback);
        }
        
        void coro_PermissionVerify(authsAPICoroPrxCallbackPtr callback,const authstars::PermissionVerifyReq &req,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriterVector> _os;
            _os.write(req, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"PermissionVerify", _os, context, _mStatus, callback, true);
        }

        authsAPIProxy* tars_hash(int64_t key)
        {
            return (authsAPIProxy*)ServantProxy::tars_hash(key);
        }

        authsAPIProxy* tars_consistent_hash(int64_t key)
        {
            return (authsAPIProxy*)ServantProxy::tars_consistent_hash(key);
        }

        authsAPIProxy* tars_set_timeout(int msecond)
        {
            return (authsAPIProxy*)ServantProxy::tars_set_timeout(msecond);
        }

        static const char* tars_prxname() { return "authsAPIProxy"; }
    };
    typedef tars::TC_AutoPtr<authsAPIProxy> authsAPIPrx;

    /* servant for server */
    class authsAPI : public tars::Servant
    {
    public:
        virtual ~authsAPI(){}
        virtual authstars::PermissionVerifyRsp PermissionVerify(const authstars::PermissionVerifyReq & req,tars::TarsCurrentPtr current) = 0;
        static void async_response_PermissionVerify(tars::TarsCurrentPtr current, const authstars::PermissionVerifyRsp &_ret)
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
            static ::std::string __authstars__authsAPI_all[]=
            {
                "PermissionVerify"
            };

            pair<string*, string*> r = equal_range(__authstars__authsAPI_all, __authstars__authsAPI_all+1, _current->getFuncName());
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __authstars__authsAPI_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    authstars::PermissionVerifyReq req;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriterVector, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                        tarsAttr.get("req", req);
                    }
                    else if (_current->getRequestVersion() == JSONVERSION)
                    {
                        tars::JsonValueObjPtr _jsonPtr = tars::JsonValueObjPtr::dynamicCast(tars::TC_Json::getValue(_current->getRequestBuffer()));
                        tars::JsonInput::readJson(req, _jsonPtr->value["req"], true);
                    }
                    else
                    {
                        _is.read(req, 1, true);
                    }
                    authstars::PermissionVerifyRsp _ret = PermissionVerify(req, _current);
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
