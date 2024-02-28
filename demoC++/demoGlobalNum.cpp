#include <iostream>

int a = 10;

int main()
{
    int a = 20;
    //::a代表这个a的作用域是全局的（为了解决全局变量和局部变量的命名冲突问题）
    std::cout<<::a<<std::endl;//全局变量
    std::cout<<a<<std::endl;//局部变量
    
    return 0;
}