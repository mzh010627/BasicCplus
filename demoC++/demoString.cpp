#include <iostream>
#include  <string>
int main()
{
    //基于动态数组实现的，不需要担心越界问题
    std::string s;
    s = "hello world";
    std::string s1 = s + "world";
    std::cout<<s1.size()<<std::endl;
    std::cout<<s1.capacity()<<std::endl;

    if (s == s1)
    {
        std::cout<<"equal"<<std::endl;
    }
    else
    {
        std::cout<<"not equal"<<std::endl;
    }
    std::cout<<s.substr(1,4)<<std::endl;
    
    return 0;
}
