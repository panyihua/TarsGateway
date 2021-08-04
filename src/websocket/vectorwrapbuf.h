//
// Created by 潘一华 on 2021/8/3.
//

#ifndef PROXY_SERVER_VECTORWRAPBUF_H
#define PROXY_SERVER_VECTORWRAPBUF_H
#include <streambuf>
#include <istream>
#include <vector>

template<typename CharT, typename TraitsT = std::char_traits<CharT> >
class VectorWrapBuf : public std::basic_streambuf<CharT, TraitsT> {
public:
    VectorWrapBuf(std::vector<CharT> &vec) {
        this->setg(&vec[0], &vec[0], &vec[0] + vec.size());
    }
    VectorWrapBuf(char* data, size_t sz) {
        this->setg(data, data, data + sz);
    }
};




#endif //PROXY_SERVER_VECTORWRAPBUF_H
