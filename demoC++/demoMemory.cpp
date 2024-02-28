#include <iostream>
#include <cstdlib>
#include <cstring>

int main()
{
#if 0
    /* 一维数组开辟空间 */
    char* str = (char*)malloc(sizeof(char) * 10);
    if (str == NULL)
        return -1;
#endif
    char** str = (char**)malloc(sizeof(char*) * 3);
    if (str == NULL)
        return -1;
    for (int i = 0; i < 3; i++)
    {
        char* str = (char*)malloc(sizeof(char) * 1);
        strcpy(str[i], "hello");
        std::cout<<str<<std::endl;
    }
    
    
    free(str);

    return 0;
    
}

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
    char **s = new char*[3];
    for (int i = 0; i < 3; i++)
    {
        s[i] = new char[10];
        strcpy(s[i], "hello");
        std::cout<<

    }
    
    return 0;


}