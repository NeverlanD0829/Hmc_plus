/*
    3.2.1deque（双队列）容器
    功能：双端数组，对头端进行插入、删除操作
    deque与vector区别：
        vector对头部插入、删除效率低，数据量大
        deque相对来说，对头部的插入删除速度比vector快
        vector访问元素时的速度比deque快，这和两者内部实现有关
    原理：deque内部有中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据。
         中控器维护的是每个缓冲区的地址，是的使用deque时像一片连续的内存空间。
    deque中迭代器也是支持随机访问的。
    
    3.2.2 构造函数
        函数原型：
            deque<T>;                   默认构造
            deque(beg,end);             将区间元素拷贝给本身
            deque(n,num);               构造函数将n个elem拷贝给本身
            deque(const deque &deq);    拷贝构造函数
    3.3.3 赋值操作
        功能：给deque容器进行赋值
        函数原型：
            deque& operator=(const deque &deq);     //重载等号操作符
            assign(beg，end);                       //将[beg, end)区间中的数据拷贝赋值给本身。
            assign(n， elem);                       //将n个elem拷贝赋值给本身。

*/

#include <iostream>
#include <string>
#include <deque>
using namespace std;

void PrintDeque(const deque<int> &d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01()
{
    deque<int> d1;                      
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    PrintDeque(d1);
    
    deque<int>d2;
    d2=d1;                               //1.重载=运算符
    PrintDeque(d2);

    deque<int>d3;
    d3.assign(d2.begin(),d2.end());     //2.将[beg, end)区间中的数据拷贝赋值给本身
    PrintDeque(d3);

    deque<int> d4;
    d4.assign(10,6);
    PrintDeque(d4);
}

int main()
{
    test01();
    return 0;
}