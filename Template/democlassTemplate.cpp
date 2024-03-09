#include <iostream>
#include <cstring>
using namespace std;

// class Point
// {
// public:
//     Point(int x, int y): m_x(x), m_y(y){}
//     Point operator+(const Point& val);
//     friend ostream& operator<<(ostream &os, const Point &val);
//     //friend 
// public:
//     int m_x;
//     int m_y;
// };

// Point Point::operator+(const Point& val)
// {
    
//     return Point(m_x + val.m_x, m_y + val.m_y);
// }

// ostream& operator<<(ostream &os, const Point &val)
// {
//     os<<"m_x:"<<val.m_x<<"\nm_y:"<<val.m_y<<endl;
//     return os;
// }

/* 类模板 */
template <typename Item>
class Array
{
private:
    Item * m_data;
    int m_size;
    int m_capacity;
    const int default_value = 10;
public:
    template <typename T>
    friend ostream& operator<<(ostream &os, const Array<Item> &val);

    Array() : Array(10){};
    Array(int capacity)
    {
        if (capacity <= 0)
        {
            capacity = default_value;
        }
        m_data = new Item[capacity];
        if (m_data == nullptr)
        {
            throw "new error";
        }
        /*清空*/
        memset(m_data, 0, sizeof(Item) * capacity);
        m_size = 0;
        m_capacity = capacity;
    
    }

    /*析构函数*/
    ~Array()
    {
        if (m_data)
        {
            delete []m_data;
        }
        
    }
private:
    bool checkIndexLegal(int index);
public:
    int add(Item value);
    void insert(int index, Item value);
    Item get(int index);
    void remove(int index);
    Item operator[](int index);
};

template <typename Item>
ostream& operator<<(ostream &os, const Array<Item> &val)
{
    
    os << "[";
    for (int idx = 0; idx < val.m_size; idx++)
    {
        if (idx != 0)
        {
            os << ", ";
        }
        
        os << val.m_data[idx];
    }
    os << "]";
    return os;
    
}


template <typename Item>
bool Array<Item>::checkIndexLegal(int index)
{
    if (index < 0 || index >= this->m_size)
    {
        return false;
    }
    
    return true;
}

/*类模板类外定义需要加上模板信息*/
template <typename Item>
int Array<Item>::add(Item value)
{
    if(this->m_size == m_capacity)
    {
        /*扩容*/
    }
    m_data[m_size++] = value;

    return 0;
}

template <typename Item>
Item Array<Item>::get(int index)
{
    if (checkIndexLegal(index))
    {
        return ;
    }
    
    return this->m_data[index];
}

template <typename Item>
Item Array<Item>::operator[](int index)
{
    
    return get(index);
}

int main()
{
    // Array<Point>array2;
    Array<int>array;
    Array<float>array3;
    return 0;
}




