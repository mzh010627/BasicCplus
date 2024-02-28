#include<iostream>
namespace A
{
    // #define size 10
    const int size = 10;
}

namespace B
{
    // #define size 20
    const int size = 20;
}

/* 不能使用define，因为命名空间对其没有约束力，会出现重复定义*/
int main()
{
    std::cout<<A::size<<std::endl;
    return 0;
}