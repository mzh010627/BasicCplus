#include<iostream>
class Interger
{
private:
    int m_a;
    
public:
 explicit Interger(int a)
{
    std::cout<<"带参构造\n";
    m_a = a;
}
~Interger()
{
    std::cout<<"无参构造\n";
}

int GetInterger()
{
    return m_a;
}
};


int main()
{
    Interger i(10);
#if 0
    /* 构造函数的隐式转换：数值会被隐式构造成类的对象，为了解决这个问题通常在构造函数前加上explicit关键字 */
    i = 20;
#endif
    std::cout<<i.GetInterger()<<std::endl;
    return 0;
}