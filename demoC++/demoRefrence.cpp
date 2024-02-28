#include<iostream>

// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void swap(int &a, int &b)//此时函数引用的就是函数外面传进来的a和b
{
    int temp = a;
    b = a;
    a = temp;
}
//void show(int &a)//只能接左值的变量不能接右值
void show(const int &a)
{
    std::cout<<a<<std::endl;
}
int main()
{
#if 0
    /* 引用不会改变指向还是b指向的a*/
    int a = 10;
    int &b = a ;//（b是a的别名）
    int c = 20;
    b = c;
#endif
#if 0
    std::cout<<a<<std::endl;
    /* 区分:下面代码b指向了c */
    int a = 10;
    int *b = &a;//指针b指向了a
    int c = 20;
    *b = &c;
#endif
#if 0
    /* 引用在函数中的表现 */
    int a = 10;
    int b = 20;
    swap(a,b);//此时传入的就是a和b，而不是把a和b复制一份到函数中，省去了取地址的过程
#endif
#if 0
    /* 引用的大小就是原变量的大小 */
    int a = 10;
    int &b = a;
    //int *const b = &a;
    std::cout<<sizeof(b)<<std::endl;//4
#endif

#if 1
    /* 左值和右值问题 */

#endif 
    /* 当show函数的参数为int &a，其为变量的别名是左值，不能直接赋右值(10)*/
    show(10);
    return 0;
}