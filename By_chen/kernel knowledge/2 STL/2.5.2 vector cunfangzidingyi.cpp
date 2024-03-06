/*
    2.1 STL诞生
        可重复利用的东西
        面向对象、泛型编程，使复用性提升
        为了建立数据结构和算法的标准，诞生了STL
    2.2 STL基本概念
        STL（standard template library）   标准模版库
        STL分为：容器，算法，迭代器
        容器和算法间通过迭代器无缝衔接
        STL几乎所有代码都采用了模版类或者模版函数
    2.3 STL六大组件
        容器：各种数据结构   vector/list/deque/set/map
        算法：常用的算法：sort/find/copy/for_each
        迭代器：容器和算法的胶合剂
        仿函数：行为类似函数，可作为算法的某种策略
        适配器（配接器）：修饰容器或者仿函数或者迭代器的接口
        空间配置器：空间配置与管理
    2.4 STL中容器、算法/迭代器
        容器：将运用最广泛的数据结构实现出来。
            STL容器是将运用最广泛的一些数据实现出来。
            常用的数据结构：数组/链表/树/栈/队列/集合/映射表
            分类：
                序列式容器：强调值排序，序列式容器中每个元素均有固定位置。
                关联式容器：二叉树结构，各元素间没有严格的物理上的顺序关系。

        算法分类：
            算法：有限的步骤解决逻辑或数学上的问题，该学科称为算法（Algorithms）。 
            质变算法：运算过程中会改变元素的内容。如：拷贝/替换/删除。
            非质变算法：运算过程中不会改变元素。  如：查找/计算/便利/寻找值。

        迭代器：
            提供一种方法能够以此访问某个容器所含的各个元素，无需暴露该容器的内部表示方式，每个容器都有自己的专属的迭代。
            可以理解为指针。 
            包括：输入迭代器/输出迭代器/前向迭代器/双向迭代器/随机访问迭代器。    最常用的容器是双向迭代器和随机访问迭代器。
        
        2.5.1 vector存放内置数据(int)类型
            容器：vector
            算法：for_each
            迭代器：vector<int>::iterator

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Person
{
    public:
        Person(string name,int age)
        {
            this->m_Name=name;
            this->m_Age=age;
        }
        string m_Name;
        int m_Age;
};

// void Myprint(Person p)
// {
//     cout<<"姓名：\t"<<p.m_Name<<"\t年龄：\t"<<p.m_Age<<endl;
// }

// void test01()
// {
//    Person p1("a",10);
//    Person p2("b",11);
//    Person p3("c",12);
//    Person p4("d",13);
//    Person p5("e",14);
//    Person p6("f",17);

//    vector<Person> v;
//    v.push_back(p1);
//    v.push_back(p2);
//    v.push_back(p3);
//    v.push_back(p4);
//    v.push_back(p5);
//    v.push_back(p6);

//for循环遍历
//    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
//    {
//         cout<<"姓名：\t"<<(*it).m_Name<<"\t年龄：\t"<<(*it).m_Age<<endl;
//    }

//利用遍历算法进行遍历
    // for_each(v.begin(),v.end(),Myprint);
// }


//存放自定义数据类型的指针
void test02()
{
   Person p1("a",10);
   Person p2("b",11);
   Person p3("c",12);
   Person p4("d",13);
   Person p5("e",14);
   Person p6("f",17);

   vector<Person*> v;
   v.push_back(&p1);
   v.push_back(&p2);
   v.push_back(&p3);
   v.push_back(&p4);
   v.push_back(&p5);
   v.push_back(&p6);

// for循环遍历
   for(vector<Person *>::iterator it=v.begin();it!=v.end();it++)
   {
        cout<<"姓名：\t"<<(*it)->m_Name<<"\t年龄：\t"<<(*it)->m_Age<<endl;      //it是一个指针，指向另一个指针*it。
   }

}

int main()
{
    // test01();
    test02();

}