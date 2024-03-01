#include<iostream>
#include<cstdlib>
class Test
{
private:
    /* dat */
public:
    Test()
    {
        std::cout<<"构造函数\n";
    }
    ~Test()
    {
        std::cout<<"析构函数\n";
    }
};

int main()
{
    // Test *t1 = (Test*)malloc(sizeof(Test));
    // Test *t = new Test();
    // delete t;
    // free(t1);
    Test *t = new Test[3];
    delete []t;
    return 0;
}