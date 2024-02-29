#include <iostream>
#include  <string>
int main()
{
    //基于动态数组实现的，不需要担心越界问题
    std::string s;
    s = "hello world";//相当于strcpy，拷贝字符串
    std::cout<<s<<std::endl;//直接输出，不需要去指针
    std::string s1 = s + "world";//相当于strcat，
    std::cout<<s1.size()<<std::endl;//计算字符串长度
    std::cout<<s1.capacity()<<std::endl;//计算动态数组容积

    s += "asd";
    s.push_back('p');//在字符串后面追加单个字符，不需要担心越界，野指针等问题
    std::cout<<s<<std::endl;
    if (s == s1)
    {
        std::cout<<"equal"<<std::endl;
    }
    else
    {
        std::cout<<"not equal"<<std::endl;
    }
    std::cout<<s.substr(1,4)<<std::endl;//截取指定的字符串
    std::cout<<s.find("l")<<std::endl;
    std::cout<<s.find_first_of("ello")<<std::endl;//查找第一个字符串匹配的位置
    
    return 0;
}
