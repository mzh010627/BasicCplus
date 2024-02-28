#include<iostream>

int main()
{
    int a = 100;
    int b = 90;
    int c = a > b ? a : b;
    // (a > b ? b:a) +=99;
    std::cout<<c<<std::endl;
    return 0;
}