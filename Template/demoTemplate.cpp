/* 模板 */
#if 0
/* 定义一个函数，实现对两个数字的相加 */
#include<iostream>
#if 0
void add(int a, int b)
{
    std::cout<<a + b<<std::endl;
}
void add(double a, double  b)
{
    std::cout<<a + b<<std::endl;
}
void add(int a, double b)
{
    std::cout<<a + b<<std::endl;
}
void add(double a, int b)
{
    std::cout<<a + b<<std::endl;
}
#endif
//那么现在如果我需要在添加上字符类的相加，是不是还需要再写函数呢？
//如果我需要相加的参数的数量增多，需要设计的函数也就会越来越多
//而且一旦需求发生变更，运算逻辑需要进行一些小小的改动，每一个函数都得修改，非常繁琐

//如果我能够设计一个通用的函数，将数据类型以“参数”的形式传入到函数的内部，让函数适配不同的数据类型，这就是函数模板


//template：定义模板关键字
//typename：定义虚拟类型的关键字，可以被替换成class
//T，M：定义的虚拟类型
template<typename T, typename M>
void add(T n1, M n2)
{
    std::cout<<n1 + n2<<std::endl;
}
template<typename T>
void mySwap(T& n1, T& n2)
{
    T temp = n1;
    n1 = n2;
    n2 = temp;
}

template<typename T1, typename T2, typename R>
//template<typename R, typename T1, typename T2>//如果函数有返回值的话，一般将返回类型的定义放在参数第一个位置，具体情况看74行代码
R calculate(T1 x, T2 y)
{
    return (R)(x + y);
}
int main()
{
    // 函数模板的使用，可以有两种方式：
    //1.显示指定类型
    add<int, double>(10, 3.14);
    add<double, int>(3.14, 10);

    //2.可以根据实参进行类型的自动推导
    add(10, 3.14);//根据实参推导类型，由10可以推到出int， 由3.14可以推导出double

    //注意事项:在进行类型推导的时候，需要注意一致性的问题，对于同样的虚拟类型，不能推导出不同的实际类型
    int x = 10;
    int y = 20;//double y = 20;(错误的他无法推导出y是什么类型)
    mySwap(x,y);
    std::cout<<"x = "<< x <<", y = "<< y <<std::endl;

    //3.调用函数模板的时候，如果手动指定虚拟类型的实际类型，此时可以不完全指定。
    //  实际给的类型，按照虚拟类型列表顺序去指定，没有指定的类型，会按照实参的类型去推导

    //4.调用函数的时候，只能根据实参来推导形参的数据类型。
    //  如果你的虚拟类型是用在返回值部分的，必须手动指定
    int res = calculate<double, double, int>(3.14, 9.99);
    //int res = calculate<int>(3.14, 9.99)//这里的int指的是返回值的类型
    std::cout<<res<<std::endl;
    return 0;
}
#endif

/* 函数模板与普通函数 */
//1.函数模板和普通函数调用， 是可以发生自动类型转换的。函数模板的调用，不会发生数据类型转换
//2.如果在调用函数的时候，实参既可以匹配普通函数，又可以匹配函数模板，优先调用普通函数
#if 0
#include<iostream>
template<typename T>
int add(T n1, T n2)
{
    std::cout<<"函数模板被调用了\n";
    return n1 + n2;
}

//普通函数定义
int add(int n1, int n2)
{
    std::cout<<"普通函数被调用了"<<std::endl;
    return n1 + n2;
}
int main()
{
    int n = 10;
    char c = 'a';
    add(n,c);//这里发生了类型转换
    add(10, 20);//这里普通函数和函数模板都可以匹配上，因此会先调用普通函数
    return 0;
}
#endif 

/* 函数模板的局限性 */
#include<iostream>
class Person
{
public:
    int age;
    Person():age(0){}
    Person(int age):age(age){}
};
// bool operator>(const Person& p1, const Person& p2)
// {
//     return p1.age > p2.age;
// }
// bool operator<(const Person& p1, const Person& p2)
// {
//     return p1.age <p2.age;
// }
//定义一个函数模板，对两个相同数据类型的数据进行比较
template<typename T>
int compare(T& n1, T& n2)
{
    if (n1 > n2)
    {
        return 1;
    }
    else if (n1 < n2)//对象不能通过这个直接进行比较
    {
        return -1;
    }
    return 0;   
}
//函数模板的重载，为了解决特定类型的对象的问题
template<>
int compare<Person>(Person& p1, Person& p2)
{
    if (p1.age > p2.age)
    {
        return 1;
    }
    else if(p1.age < p2.age)
    {
        return -1;
    }  
    return 0;
}
int main()
{
    //创建两个Person对象
    Person xiaobai(19);
    Person xiaohei(20);
    std::cout<<compare(xiaobai, xiaohei)<<std::endl;
    return 0;
}