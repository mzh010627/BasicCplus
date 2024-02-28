#include<iostream>
#include<cstring>
#if 0
int add(int a, int b, int c = 0);//当参数c不进行传值操作时给0，称为默认参数
int add(int a,int b,int c)
{
    return a + b + c;
}
#endif

#if 1
bool func(int a, char *errorMsg = NULL)
{
    strcpy(errorMsg, "connect error!\n");
    return false;
}
#endif
int main()
{
    //std::cout<<add(10,20)<<std::endl;
    char msg[1024] = {0};
    if (func(1,msg) == false)
    {
        std::cout<<msg<<std::endl;
    }
    
    return 0;
}