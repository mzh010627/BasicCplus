#ifndef _TEST_H_
#define _TEST_H_
#ifdef __cplusplus//加上这段c的编译器就知道这里引用了c++的东西，在编译也能通过了
extern "C"  //让c++编译器知道这是c编译完的文件，但是再去用gcc编译时C语言就不认得了
{
#endif
    void func();
#ifdef __cplusplus
}
#endif
#endif