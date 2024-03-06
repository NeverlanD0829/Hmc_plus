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
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;

void PrintSet(set<int> &s)
{
    for(set<int>::const_iterator it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01()
{
    set<int> s1;            //特点：所有元素插入时自动排序，且不允许插入重复的数据。
    s1.insert(12);
    s1.insert(31);
    s1.insert(17);
    s1.insert(25);
    PrintSet(s1);

    set<int>s2(s1);         //赋值
    PrintSet(s2);

    set<int>s3;
    s3=s2;
    PrintSet(s3);
    


}

int main()
{

    test01();
    return 0;
}