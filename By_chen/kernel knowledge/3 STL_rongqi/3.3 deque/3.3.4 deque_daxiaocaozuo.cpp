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
    3.3.4 deque大小操作
        功能：对deque容器的大小进行操作
        函数原型：
            deque.empty();			//判断容器是否为空
            deque.size();			//返回容器中元素的个数
            deque.resize(num);		//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
            deque.resize(num,elem); //如果容器变短，则末尾超出容器长度的元素被删除。
                                    //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
                                    //如果容器变短，则末尾超出容器长度的元素被删除。
        注意：deque容器没有容量capacity的概念。

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
    
    if(d1.empty())
    {
        cout<<"deque容器为空"<<endl;
    }
    else
    {
        cout<<"d1的大小为："<<d1.size()<<endl;
    }
    d1.resize(12);
    PrintDeque(d1);
    d1.resize(20,1);
    PrintDeque(d1);
   

}

int main()
{
    test01();
    return 0;
}