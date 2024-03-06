/*
    简介：
        map中所有元素都是pair
        pair中第一个元素为key（键值），第二个元素为value（实值）
        所有元素都会根据元素 键值 自动排序

    本质：
        map/multimap 属于关联式容器，底层结构用二叉树实现。
    
    优点：
        可以根据key值快速找到value

    map和multimap区别：
        map中不允许容器中有重复的  key值    元素
        multimap允许容器中有重复的  key值  元素
    3.8.1 构造和赋值
        功能描述:对map容器进行构造和赋值操作
        构造:
            map<T1，T2> mp;//map默认构造函数:
            map(const map &mp);//拷贝构造函数
        赋值:
            map& operator=(const map &mp);//重载等号操作符
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

void PrintMap(map<int,int> &m)
{
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++)           //it是迭代器，也支持*操作
    {
        // cout<<"key="<<(*it).first<<"\tvalue="<<(*it).second<<endl;      
        cout<<"key="<<it->first<<"\tvalue="<<it->second<<endl;      
    }
    cout<<endl;
}

void test01()
{
    map<int,int> m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(3,20));
    m.insert(pair<int,int>(2,30));
    m.insert(pair<int,int>(4,40));
    PrintMap(m);

    map<int,int>m2(m);                     //拷贝构造
    PrintMap(m2);

    map<int,int>m3;
    m3=m2;
    PrintMap(m3);
}

int main()
{
    test01();
    return 0;
}