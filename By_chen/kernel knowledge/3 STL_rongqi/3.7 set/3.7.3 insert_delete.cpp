/*
    3.7 Set容器简介：
        所有元素在插入时自动被排序
        本质：
            set/multiset 属于关联式容器，底层结构是二叉树实现。
        set、multiset 区别：
            set不容许容器中有重复的元素
            multiset允许容器中有重复的元素
    3.7.1 set构造和赋值
        set<T> st;//默认构造函数:
        set(const set &st);//拷贝构造函数
        赋值:
        set& operator=(const set &st);//重载等号操作符 
    3.7.2 set大小和交换
        size（）、empty（）、swap（st）     set容器不支持resize（）重新指定的大小
    3.7.3 插入和删除
        set和multiset的区别
            set 不可以插入重复的值  set插入数据的同时会返回插入结果 返回插入十分成功
            multiset 可以插入重复的值
        insert(elem);                       //在容器中插入元素。
        clear();                            //清除所有元素
        erase(pos);                         //删除pos迭代器所指的元素，返回下一个元素的迭代器。
        erase(beg,end);                     //删除区间[beg,end)的所有元素，返回下一个元素的迭代器。
        erase(elem);		                //删除容器中值为elem的元素。

*/
#include <iostream>
#include <string>
#include <set>
using namespace std;

void PrintSet(multiset<int> &s)
{
    if(!s.empty())
    {
        for(set<int>::const_iterator it=s.begin();it!=s.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"set容器为空"<<endl;
    }
    
}

void test01()
{
    // set<int> s1;            //特点：所有元素插入时自动排序，且不允许插入重复的数据。
    multiset<int> s1;            //特点：所有元素插入时自动排序，且不允许插入重复的数据。
    s1.insert(12);
    s1.insert(12);
    s1.insert(31);
    s1.insert(25);
    PrintSet(s1);
    set<int>::iterator it=s1.begin();
    set<int>::iterator st=s1.end();
    it++;

    s1.erase(it);
    PrintSet(s1);

    s1.erase(31);
    PrintSet(s1);
    s1.erase(s1.begin(),s1.end());
    PrintSet(s1);
    s1.clear();
    PrintSet(s1);
}

int main()
{

    test01();
    return 0;
}