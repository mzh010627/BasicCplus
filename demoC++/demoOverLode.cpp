#include<iostream>
/* 函数编译时会将参数和函数名重新编译成新的函数名*/
int add(int a, int b)//编译时编译成_init_init_add新函数名
{
    return a + b;
}
#if 0
/* 返回值不同不能作为重载函数 */
short add(int a, int b)
{
    return a + b;
}
#endif
double add(double a, double b)//编译成_double_double_add新函数名
{
    return a + b;
}

int main()
{
    std::cout<<add(1,2)<<std::endl;
    return 0;
}