#include<iostream>

class Test
{
private:
    const int m_a;//常成员变量,初始化必须在成员列表中完成
    int b;
public:
    Test(int a):m_a(a),b(b)//参数初始化列表
    {
    }
    void show()
    {
        std::cout<<m_a<<std::endl;
    }
    
};


int main()
{
    Test t(1);
    t.show();
    return 0;
}
