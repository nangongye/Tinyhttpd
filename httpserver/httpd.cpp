#include "httpd.h"
#include<string.h>
#include<string>
#include<stdlib.h>
#include<ctype.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
 __int32_t Httpd::startUp(uint16_t* port){
    /*用以接收socket返回的文件描述符。Receive the return value of the socket*/
    __int32_t httpd = 0;
    __int32_t on = 1;
    struct sockaddr_in name;

    httpd = socket(PF_INET, SOCK_STREAM, 0);
    if(httpd == -1)
        errorInfo("calling socket faile");
    
    //将name中sizeof(name)个替换成0。replace the sizeof(name) of name with 0.
    memset(&name, 0, sizeof(name));
    name.sin_family = AF_INET;//ipv4地址
    name.sin_port = *port;//port number
    name.sin_addr.s_addr = htonl(INADDR_ANY);//internet address

    if((setsockopt(httpd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))) < 0)
        errorInfo("setsocket failed");
    
    if(bind(httpd, (struct sockaddr*)& name, sizeof(name)) < 0)
        errorInfo("Error while binding");
    
    if(*port == 0){//if dynamically allocating a port 如果动态分配端口
        socklen_t namelen = sizeof(name);
        if(getsockname(httpd, (struct sockaddr*)& name, &namelen) == -1)
            errorInfo("getsockname faile");  
        *port = name.sin_port;
    }

    //在上一步的连接请求被拒接之前5个连接请求将会排队
    if(listen(httpd,5) < 0)
        errorInfo("listen faile");
    return httpd;
}

void Httpd::errorInfo(const std::string Info){
    //prror(Info);
    std::cout << Info << std::endl;
    exit(1);
}


void Httpd::acceptRequest(__int64_t* arg){
    __int64_t* client = arg;
    std::string buf[1024] = "";//buffer
    __int32_t numchars;

    std::string method[255] = "";
    std::string url[255] ="";//saving url
    std::string path[512] = "";//saving path
    size_t i = 0,j = 0;


    //View various information about a file
    //查看文件的各种信息，如设备的名称，组id等
    struct stat st;

    /* becomes true if server decides this is a CGI
    * program
    如果是cgi，则为真 */
    __int32_t cgi = 0;
    std::string* queryString = nullptr;
    
    numchars = get_line(client, buf, sizeof(buf));
    while(i < sizeof(method) - 1){

    }
}

__int32_t Httpd::get_line(__int32_t* sock, std::string* buf, __int32_t size){

}