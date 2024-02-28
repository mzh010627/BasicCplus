#include<iostream>


enum COLOR 
{
    black,
    white
};

enum RGB
{
    red,
    green,
    blue
};

/* 当enum加上class时，下面main中的代码编译是完全无法通过的的 */
// enum class COLOR 
// {
//     black,
//     white
// };

// enum class RGB
// {
//     red,
//     green,
//     blue
// };

int main()
{
    /* 枚举体的发明就是为了增强语意的 */
    /* 在C语言中white和green都是代表的状态码的值1，所以是相等，但是语意上是不同的，在c++中依然可以编译通过，但是会报警告,因为他们属于不同类型的枚举，之间的比较是不安全的*/
    
    if (COLOR::white == RGB::green)
    {
        std::cout<<"euqal"<<std::endl;
    }
    

    return 0;
}