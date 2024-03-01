#include<iostream>
class Test
{
public:
    Test()
    {
        count++;
        std::cout<<"构造函数\n";
    }
    ~Test()
    {
        count--;
        std::cout<<"析构函数\n";
    }
public:
    // static int c;
    static int count;
};
/* 静态成员变量的初始化 */
int Test::count = 0;
int main()
{
    //std::cout<<Test::c<<std::endl;
    // Test t1;
    // t1.c = 10;
    // Test t2;
    // std::cout<<t2.c<<std::endl;
    Test *t1 = new Test();
    Test *t2 = new Test();
    delete t1 ;
    std::cout<<Test::count<<std::endl;

    return 0;
}