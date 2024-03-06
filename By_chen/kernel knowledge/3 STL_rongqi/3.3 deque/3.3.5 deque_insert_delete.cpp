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
    3.3.5 deque删除和插入
        作用：向deque容器中插入和删除数据

        函数原型：
            两端插入操作:
                push_back(elem);//在容器尾部添加—个数据
                push_front(elem);//在容器头部插入一个数据
                pop_back();//删除容器最后一个数据
                pop_front();//删除容器第一个数据

            指定位置操作:
                insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
                insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
                insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
                clear();//清空容器的所有数据
                erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
                erase(pos);//删除pos位置的数据，返回下一个数据的位置。

*/

#include <iostream>
#include <string>
#include <deque>
using namespace std;

void PrintDeque(const deque<int> &d)
{
    if(d.empty())
    {
        cout<<"deque容器为空"<<endl;
    }
    else
    {
        for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

void test01()
{
    deque<int> d1;                      
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(100);
    d1.push_back(200);          //尾插
    PrintDeque(d1);
    d1.push_front(455);
    PrintDeque(d1);

    d1.pop_back();              //删除容器最后一个数据
    PrintDeque(d1);
    d1.pop_front();             //删除第一个数据
    PrintDeque(d1);
    
}

void test02()
{
    deque<int> d1;                      
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(100);
    d1.push_back(200);             //尾插
    PrintDeque(d1);

    d1.insert(d1.begin(),1000);     //pos位置插入一个elem元素的拷贝，返回新数据的位置
    PrintDeque(d1);

    d1.insert(d1.begin(),2,1000);   //在pos位置插入n个elem数据，无返回值
    PrintDeque(d1);

    deque<int> d2;
    d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

    d1.insert(d1.begin(),d2.begin(),d2.end());          //在pos位置插入[beg,end)区间的数据，无返回值
    PrintDeque(d1);
}
//删除：
void test03()
{
    deque<int> d1;                      
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(100);
    d1.push_back(200);  
    PrintDeque(d1);

    deque<int>::iterator it=d1.begin();
    it++;
    d1.erase(it);                       //删除begin()下一个元素
    PrintDeque(d1);

    d1.erase(d1.begin(),d1.end());      //删除整个容器中的元素
    PrintDeque(d1);

    d1.push_back(100);
    d1.push_back(200);  
    PrintDeque(d1);
    d1.clear();                         //clear方法删除整个容器中的元素
    PrintDeque(d1);
}
int main()
{
    // test01();
    // test02();
    test03();
    return 0;
}