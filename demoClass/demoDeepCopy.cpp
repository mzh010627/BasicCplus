#include<iostream>

class Test
{
private:
    // int *p;
public:
    Test()
    {
        // p = new int;
        std::cout<<"构造函数\n";
    }
    Test(const Test&t)
    {
        std::cout<<"拷贝构造\n";
        // p = new int;
        // *p = *t.p;
    }
    ~Test()
    {
        // delete p;
        std::cout<<"析构函数\n";
    }
};
#if 0
/* 这里调用构造函数去构造t，但是此时的t为局部变量，跳出这个函数就死掉了，所以他返回的是t的内存的值，相当于匿名对象，不会调用*/
Test func()
{
    Test t;
    std::cout<<"-------\n";
    return t;
}
#endif
#if 0
Test& func()
{
    static Test t;
    std::cout<<"-------\n";
    return t;
}
#else
Test& func(Test& t)
{
    printf("-------\n");
    return t;
}
#endif

int  main()
{
    // Test t;
    // Test t2 = t;
    // Test();//匿名对象：声明周期只有一行代码
    // std::cout<<"---------\n";
    Test t;
    Test t1;
    t1 = func(t);
    return 0;
}