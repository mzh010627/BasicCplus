#include<iostream>

int main()
{
    bool a = true;
    bool b = false;
    bool c = 1000;
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    std::cout<<sizeof(a)<<std::endl;
    std::cout<<sizeof(b)<<std::endl;
    /* 赋非0值都是1 */
    std::cout<<c<<std::endl;
    return 0;
}