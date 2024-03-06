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
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;

void PrintSet(set<int> &s)
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
    set<int> s1;            //特点：所有元素插入时自动排序，且不允许插入重复的数据。
    s1.insert(12);
    s1.insert(31);
    s1.insert(17);
    s1.insert(25);
    PrintSet(s1);
    cout<<"s1的大小："<<s1.size()<<endl;
    
    set<int> s2;            //特点：所有元素插入时自动排序，且不允许插入重复的数据。
    s2.insert(144);
    s2.insert(332);
    s2.insert(197);
    s2.insert(265);
    cout<<"交换前："<<endl;
    PrintSet(s1);
    PrintSet(s2);
    
    s1.swap(s2);
    cout<<"交换后："<<endl;
    PrintSet(s1);
    PrintSet(s2);
}

int main()
{

    test01();
    return 0;
}