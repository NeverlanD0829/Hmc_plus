/*
    3.6 list容器
        3.6.1 list基本概念
            功能：将数据进行链式存储。  链表是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
            组成：链表由一系列节点组成。
            节点的组成：一个是存储数据元素的数据域，另一个是存储下一个节点地址的指针域。
            STL中的链表是：双向循环链表。

            链表的存储方式不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器。

        list优点：
            采用动态内存分配，不会造成内存浪费和溢出。
            链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素。
        list缺点：
            链表灵活，但空间（指针域）和时间（遍历）额外耗费大。
            list又一个重要性质：
                插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。
        
        3.6.2 list构造函数
            功能描述：创建list容器。
            函数原型：
            list<T> lst;                    //list采用采用模板类实现.对象的默认构造形式:
            list(beg,end);                  //构造函数将[beg, end)区间中的元素拷贝给本身。
            list(n,elem);                   //构造函数将n个elem拷贝给本身。
            list(cons list &lst);           //拷贝构造函数。   
*/
#include <iostream>
#include <string>
#include <list>
using namespace std;

void PrintList(const list<int>&l)
{
    for(list<int>::const_iterator it=l.begin();it!=l.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    PrintList(l1);

    list<int> l2(l1.begin(),l1.end());          //区间构造
    PrintList(l2);

    list<int> l3(l2);                           //拷贝构造
    PrintList(l3);

    list<int> l4(8,12);                           //拷贝构造
    PrintList(l4);
}

int main()
{
    test01();
    return 0;
}

