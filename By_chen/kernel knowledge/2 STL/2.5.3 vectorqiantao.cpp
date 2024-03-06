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
        
        2.5.3 容器中嵌套容器，将所有数据遍历输出（类似于二维数组）


*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void test01()
{
    vector<vector<int> > v;          //定义大容器
    vector<int> v1;                 //定义小容器
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    for(int i=0;i<4;i++)            //向小容器中装数据
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }
    //小容器装入大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    //遍历大容器
    for (vector<vector<int> >::iterator it=v.begin();it!=v.end();it++)
    {
        //*it也是一个容器，遍历小容器
        for (vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++)
        {
            cout<<*vit<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    test01();

}