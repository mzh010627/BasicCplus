#include<iostream>
inline int func(int *a)
{
    return (*a + 1);
}

int main()
{
    int a = 10;
    a = func(&a);
    std::cout<<a<<std::endl;
    return 0;
}