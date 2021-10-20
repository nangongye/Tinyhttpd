#ifndef __HTTPSERVER_HTTP_H__
#define __HTTPSERVER_HTTP_H__

#include <iostream>
#include "server.h"
#include<string>
class Httpd : public Servers{
public:
     Httpd() {}
    ~Httpd() {}
    virtual __int32_t startUp(uint16_t* port);

    /*return error request返回错误请求*/
    virtual __int32_t errorRequest(__int32_t* arg);

    //accept http request接收http请求
    virtual void acceptRequest(__int64_t* arg);
    virtual void errorInfo(const std::string Info);
    virtual __int32_t get_line(__int32_t* sock, std::string* buf, __int32_t size);

    
};

#endif