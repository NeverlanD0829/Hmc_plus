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
        3.6.3 赋值交换
            函数原型:
                assign(beg, end);                   /将[beg,end)区间中的数据拷贝赋值给本身。
                assign(n， elem);                   //将n个elem拷贝赋值给本身。
                list& operator=(const list &lst);   //重载等号操作符
                swap(lst);                          //将lst与本身的元素互换。
        3.6.4 list大小操作
            函数原型：
                size();                      //返回容器中元素的个数
                empty();                    //判断容器是否为空
                resize(num);                //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
                                            //如果容器变短，则末尾超出容器长度的元素被删除。
                resize(num，elem);          //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
                                            //如果容器变短，则末尾超出容器长度的元素被删除。
        3.6.5 insert_delete
            函数原型:
                push_back(elem);            //在容器尾部加入一个元素
                pop_back();                 //删除容器中最后一个元素
                push_front(elem);           //在容器开头插入一个元素
                pop_front();                //从容器开头移除第一个元素
                insert(pos,elem);           //在pos位置插elem元素的拷贝，返回新数据的位置。
                insert(pos,n,elem);         //在pos位置插入n个elem数据，无返回值。
                insert(pos,beg,end);        //在pos位置插入[beg,end)区间的数据，无返回值。
                clear();                    //移除容器的所有数据
                
                erase(beg,end);             //删除[beg,end)区间的数据，返回下一个数据的位置。
                erase(pos);                 //删除pos位置的数据，返回下一个数据的位置。
                remove(elem);               //删除容器中所有与elem值匹配的元素。

*/
#include <iostream>
#include <string>
#include <list>
using namespace std;


void printList(const list<int>&l)
{
    if(!l.empty())
    {
        for(list<int>::const_iterator it=l.begin();it!=l.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"List容器为空"<<endl;
    }
}

void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	L1.push_front(400);
	L1.push_front(300);
	L1.push_front(200);
	L1.push_front(100);
	printList(L1);

	L1.insert(L1.begin(), 1000);
	printList(L1);

	L1.erase(L1.begin());
	printList(L1);

	L1.pop_back();
	L1.pop_front();
	printList(L1);

    list<int>::iterator it=L1.begin();
    L1.insert(++it,10000);
    printList(L1);                          //200 10000 300 400 10 20 30 

    it=L1.begin();
    L1.erase(++it);                           //此时，it指针指向
    printList(L1);      

    L1.push_back(10000);  
    printList(L1);                       
    L1.push_back(10000);                       //尾插两个10000
    printList(L1);  

    L1.remove(10000);
    printList(L1);
    L1.clear();
    printList(L1);                       
}

int main()
{
    test01();
    return 0;
}

