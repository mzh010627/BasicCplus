#include <iostream>
#include <cstdlib>
#include <cstring>


#if 0
int main()
{

    /* 一维数组开辟空间 */
    char* str = (char*)malloc(sizeof(char) * 10);
    if (str == NULL)
        return -1;
    //str = "hello";//当你写下 str = "hello "; 时，实际上是将字符串常量 "hello " 的地址赋给了指针变量 str，而不是将 "hello " 这个字符串复制到 str 指向的内存中,这会导致两个问题：
    /* 1.内存泄漏：在你调用 malloc 分配内存之后，将 "hello " 的地址赋给 str，原本分配的内存空间就无法访问到了，导致内存泄漏 */
    /* 2.字符串常量不可更改：字符串常量是不可更改的，试图修改字符串常量所在的内存会导致未定义的行为 */
    strcpy(str,"hello");
    std::count<<str<<std::endl;
    free(str);
    rerturn 0;
#endif

#if 0
    char** str = (char**)malloc(sizeof(char*) * 3);
    if (str == NULL)
        return -1;
    for (int i = 0; i < 3; i++)
    {
        if (str[i] == NULL)
        {
            str[i] = (char*)malloc(sizeof(char) * 10);
            if (str[i] == NULL)
            {
                return -1;
            }
            strcpy(str[i], "hello");
        }
    }
    for (int i = 0; i < 3; i++)
    {
        std::cout<<str[i]<<std::endl;
    }
    /* 释放空间 */
    for (int i = 0; i < 3; i++)
    {
        free(str[i]);
    }
     
    free(str);

    return 0;
  
}
#endif
int main()
{
#if 0
    char *s = (char*)malloc(sizeof(char) *10);
    char *s = new char[10];
    //1.不需要计算内存大小
    //2.不需要对指针进行转换
    //3.不需要判断至臻是否为空：抛出异常，终止程序
    strcpy(s, "hello");
    std::cout<<s<<std::endl;

    // 释放数组
    delete []s;

    int *a = new int(10); //()是赋值，[]是申请数组
    std::cout<<*a<<std::endl;
    delete a;
#endif

#if 0
    //char *s = (char*)malloc(sizeof(char) *10); //c
    char **s = new char*[3]; //c++
    //1.不需要计算内存大小
    //2.不需要对指针进行转换
    //3.不需要判断指针是否为空：抛出异常，终止程序
    strcpy(s,"hello");
    //释放数组
    delete []s;
#endif
#if 1
    int *a = new int(10); //小括号是赋值，[]申请数组
    std::cout<<*a<<std::endl;
    delete a;
    char **s = new char*[3];
    for (int i = 0; i < 3; i++)
    {
        s[i] = new char[10];
        strcpy(s[i], "hello");
        std::cout<<s[i]<<std::endl;

    }
    for (int i = 0; i < 3; i++)
    {
        delete []s[i];
    }
    delete []s;
    
    return 0;

#endif
}