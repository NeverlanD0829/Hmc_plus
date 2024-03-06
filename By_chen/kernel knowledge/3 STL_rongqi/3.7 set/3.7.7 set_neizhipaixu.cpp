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
    3.7.4 查找和统计
        find(key)       查找key是否存在 若存在 返回该键的元素的迭代器 若不存在 返回set.end()
        count(key)      统计key的元素个数
    3.7.5 set和multiset的区别
            set         不可以插入重复的值  set插入数据的同时会返回插入结果 返回插入十分成功
            multiset    不会检测数据，因此可以插入重复的值
    3.7.6 pair对组
        pair队组创建
        方式一：pair<type,type> p(value1,value2)
        方式二：pair<type,type> p=make_pair(value1,value2)
    3.7.7 set内置数据类型排序
        set默认排序为：从小到大。
        主要技术点：利用仿函数，改变排序规则
    
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;

class MyCompare
{
    public:
        bool operator()(const int v1,const int v2)const
        {
            return v1>v2;
        }
};

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

void PrintSet2(set<int,MyCompare> &s)
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
    set<int>s1;
    s1.insert(12);
    s1.insert(14);
    s1.insert(16);
    s1.insert(11);
    s1.insert(13);
    s1.insert(19);
    PrintSet(s1);

    //指定排序规则为从大到小，插入之前指定规则

    set<int,MyCompare>s2;   
    s2.insert(12);
    s2.insert(14);
    s2.insert(16);
    s2.insert(11);
    s2.insert(13);
    s2.insert(19);
    PrintSet2(s2);


}

int main()
{
    test01();
    return 0;
}