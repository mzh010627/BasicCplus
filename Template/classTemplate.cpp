/* 类模板 */
#if 0
#include<iostream>

template<typename T1, typename T2>
class NumberCalculator
{
private:
    T1 n1;  
    T2 n2;
public:
    NumberCalculator(){}
    NumberCalculator(T1 x, T2 y):n1(x), n2(y){}
    void showAdd()
    {
        std::cout<<n1+n2<<std::endl;
    }
    void showMinus()
    {
        std::cout<<n1-n1<<std::endl;
    }
};
//普通函数中，使用类模板作为参数，类模板必须明确类型
void useCalculator(NumberCalculator<int, int>& op)
{
    op.showAdd();
}

//函数模板中，使用到类模板作为参数的时候，类模板可以确定类型，也可以使用函数模板中的虚拟类型
template<typename X, typename Y>
void useCalculator2(NumberCalculator<X, Y>& op)
{
    op.showMinus();
}
int main()
{
    //类模板对象创建的时候，必须手动指定类型，不能通过再 推导的方式来确定类型

    //创建对象
    NumberCalculator<int, int> cal1(10, 20);
    cal1.showAdd();

    //创建对象
    NumberCalculator<double, double> cal2(20, 20);
    useCalculator2(cal2);
    return 0; 
}
#endif

#if 1
#include<iostream>

//类模板中，成员函数的创建时机
class Dog
{
public:
    void bark()
    {
        std::cout<<"Dog dark"<<std::endl;
    }
};

class Cat
{
public:
    void sleep()
    {
        std::cout<<"Cat sleep\n";
    }
};

template<typename T>
class Person
{
public:
    T pet;

    void makeBark()
    {
        pet.bark();
    }
    void makeSleep()
    {
        pet.sleep();
    }
};
int main()
{
    //在设计完成之后，直接编译程序，直接编译程序，发现没有问题

    //调用makeBark函数的时候，可以正常调用，没有问题
    Person<Dog> xiaobai;
    xiaobai.makeBark();
    //pet对象调不到sleep（）函数，原因：类模板中的成员函数，是在调用函数的时候才会创建的，因为在编译的时候只知道有一个对象是pet，但是具体是什么类型不知道
    //在调用makeBark函数的时候，创建这个函数，而我们设置的类型是dog类型，没有问题
    //在调用makeSleep函数的时候，创建这个函数，而我们设置的类型是dog类型，没有sleep函数，因此就出问题了
    xiaobai.makeSleep();
    return 0;
}
#endif