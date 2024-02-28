#include<iostream>
struct StdTcpServer
{
    int a;
    int b;
};
/* 类似于C语言中的typedef StdTcpServer TcpS */
using  TcpS = StdTcpServer;
int main()
{
    //struct.StdTcpServer.a = 10;在C语言中必须要加上struct.
    TcpS s;

    return 0;
}