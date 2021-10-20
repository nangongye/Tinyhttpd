#ifndef __HTTPSERVER_SERVER_H__
#define __HTTPSERVER_SERVER_H__

#include<iostream>

//abstract class抽象类
class Servers{
public:
    Servers(){}
    virtual ~Servers(){}
    /*initialize the servers,including setting up
        sockets,bingding port and listening.
        初始化服务器，建立套接字，绑定端口并监听
    */
    virtual __int32_t startUp(uint16_t* port) = 0;

    /*return error request返回错误请求*/
    virtual __int32_t errorRequest(__int32_t* arg) = 0;

    //accept http request接收http请求
    virtual void acceptRequest(__int64_t* arg);
};
#endif