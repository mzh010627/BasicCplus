#include<iostream>
#include<string>
class Student
{
public:
#if 1
//无参构造
    Student()
    {
        std::cout<<"无参构造\n";
    }
#endif
    Student(int age, const std::string & name)
    {
        m_age = age;
        m_name = name;
        std::cout<<"带参构造\n";
    }
    Student(const  std::string & name)
    {
        m_age = 0;
        m_name = name;
    }
    /* 拷贝构造 */
    Student(const Student& s)
    {
        std::cout<<"拷贝构造函数"<<std::endl;
        m_age = s.m_age;
        m_name = s.m_name;
    }
    //赋值运算符的函数重载
    void operator = (const Student& s)
    {
        std::cout<<"赋值运算符的重载"<<std::endl;
        m_age = s.m_age;
        m_name = s.m_name;

    }
    /*析构函数*/
    ~Student()
    {
        std::cout<<"析构函数"<<std::endl;
    }

    //类内声明
    void SetAge(int age);
    int GetAge();
    void SetName(const std::string & name);
    std::string GetName();

private:
    int m_age;
    std::string m_name;
};

//类外定义
void Student::SetAge(int age)
{
    m_age = age;
}

int Student::GetAge()
{
    return m_age;
}

void Student::SetName(const std::string &name)
{
    m_name = name;
}

std::string Student::GetName()
{
    return m_name;
}


int main()
{
    Student s(1,"zhangsan");
    std::cout<<s.GetAge()<<std::endl;
#if 0
    Student s1(s);//等价于Student s1 = s；(拷贝构造)
    std::cout<<s1.GetAge()<<std::endl;
#endif

    Student s1;//先无参构造
    s1 = s;    //再赋值
    std::cout<<s1.GetAge()<<std::endl;

    return 0;
}

