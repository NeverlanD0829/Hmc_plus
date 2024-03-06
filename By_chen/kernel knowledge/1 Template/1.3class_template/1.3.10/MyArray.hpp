#ifndef MYARRAY_H
#define MYARRAY_H
#include <iostream>
using namespace std;
template <class T>
class MyArray
{
public:
    // 有参构造
    MyArray(int capacity)
    {
        // cout << "有参构造" << endl;
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];
    }
    // 拷贝构造
    MyArray(const MyArray &arr)
    {
        // cout << "拷贝构造" << endl;
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        // this->pAddress=arr.pAddress;编译器写法，但指针不能这样赋值,出现浅拷贝问题
        // 深拷贝
        this->pAddress = new T[arr.m_Capacity];
        // 将arr中的数据拷贝过来
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    // operator=防止浅拷贝 a=b=c，返回自身的引用，可以进行连等
    MyArray &operator=(const MyArray &arr) // 这个const是防止误调用
    {
        // cout << "=" << endl;
        if (this->pAddress != NULL) // 首先判断原来的堆区里是否有数据，如果有先释放
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        // 深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[arr.m_Capacity];
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this; // 返回自身
    }
    // 尾插法
    void Push_Back(const T &val)
    {
        // 判断容量
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }
    // 尾删法
    void Pop_back()
    {
        // 让用户访问不到最后一个元素
        if (this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;
    }
    // 访问第N个元素
    T &operator[](int index) // 若想要返回可以作为左值，需要加引用！！！
    {
        return this->pAddress[index];
    }
    // 返回容量和大小
    int getCapacity()
    {
        return this->m_Capacity;
    }
    int getSize()
    {
        return this->m_Size;
    }
    // 析构函数
    ~MyArray()
    {
        // cout << "析构函数" << endl;
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T *pAddress;
    int m_Capacity;
    int m_Size;
};



#endif