//
// Created by 潘一华 on 2021/8/3.
//
#include "vectorwrapbuf.h"
#include <iostream>
#include <string.h>
using namespace std;
int test()
{
    std::vector<char> data{'a', '2', 'e'};
    char* d = (char*)"asdf2222fa";
    VectorWrapBuf<char> buf(d, strlen(d));
    std::istream is(&buf);
    char c;
    while (is.good())
    {
        c = is.get();

        cout << c <<endl;
    }
    return 0;
}

