#include<iostream>
#if 0
/* C语言中不允许创建两个名字相同的函数，即使他们的参数不同，功能不同，于是c++加入了命名空间的概念去解决命名冲突的问题*/
void InserterTail(int *num, int len)
{

}


void InserterTail(double *num, int len)
{
    
}
#endif
/* 不要将using namespace std在全局区使用 ，因为c++的库里有和c的库里同名的函数，当你在全局区里使用std时，你在main函数中使用函数时会默认使用成c++的库*/
namespace A
{
    void InserterTail()
    {
        std::cout<<"first"<<std::endl;
    }
    int a = 10;
}

namespace B
{
    void InserterTail()
    {
        std::cout<<"second"<<std::endl;
    }
    int a = 20;
}

namespace C
{
    void InserterTail()
    {
        std::cout<<"third"<<std::endl;
    }
    int a = 20;
    namespace B
    {
        int a = 30;
    }
}
/*当using定义在全局区的时候，main函数中会默认使用c空间的变量和函数，但是其他空间有同名的变量时，需要在main中用域解析符声明清楚是哪个空间的变量否则会有变量不明确的错误*/
//using namespace C;

int main()
{
    using namespace C; 
    InserterTail();

    std::cout<<C::B::a<<std::endl;
    return 0;
}
