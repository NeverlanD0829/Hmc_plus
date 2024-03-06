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
    3.8.2 大小和交换
        函数原型:
            size();                     //返回容器中元素的数目
            empty();                    //判断容器是否为空
            swap(st);                   //交换两个集合容器
    3.8.3 map插入和删除
        函数原型:
            insert(elem);               //在容器中插入元素。
            clear();                    //清除所有元素
            erase(pos);                 //删除pos迭代器所指的元素，返回下一个元素的迭代器。
            erase(beg,end);             //删除区间[beg,end)的所有元素，返回下一个元素的迭代器。
            erase(key);                 //删除容器中值为key的元素。
    3.8.4 map查找和统计
        功能：查找和统计
            find（key）;                //查找key是否存在，存在，则返回该键的元素的迭代器。     若不存在，返回set.end();
            count(key);                //统计key元素的个数。
    3.8.5 map排序
        map默认排序规则为从小到大。
        改变方式：利用仿函数，改变排序规则。
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

class ComPare
{
    public:
        bool operator()(int v1,int v2)const                 //const 关键字声明该成员函数是一个常量成员函数，成员函数是一个函数调用运算符的重载，const 声明表明这个成员函数不会修改类的成员变量。
        {
            return v1>v2;
        }
};

void PrintMap(map<int,int> &m)
{
    if(!m.empty())
    {
        for(map<int,int>::iterator it=m.begin();it!=m.end();it++)           //it是迭代器，也支持*操作
        {
            // cout<<"key="<<(*it).first<<"\tvalue="<<(*it).second<<endl;      
            cout<<"key="<<it->first<<"\tvalue="<<it->second<<endl;      
        }
        cout<<"map容器的元素数目为:"<<m.size()<<endl;
    }
    else
    {
        cout<<"Map容器为空"<<endl;
    }
}

void PrintMap2(map<int,int,ComPare> &m)
{
    if(!m.empty())
    {
        for(map<int,int,ComPare>::iterator it=m.begin();it!=m.end();it++)           //it是迭代器，也支持*操作
        {
            // cout<<"key="<<(*it).first<<"\tvalue="<<(*it).second<<endl;      
            cout<<"key="<<it->first<<"\tvalue="<<it->second<<endl;      
        }
        cout<<"map容器的元素数目为:"<<m.size()<<endl;
    }
    else
    {
        cout<<"Map容器为空"<<endl;
    }
}

void test01()
{
    map<int,int> m;                                 
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(5,50));
    m.insert(pair<int,int>(3,30));
    m.insert(pair<int,int>(4,40));
    PrintMap(m);

    map<int,int,ComPare> m1;                                 //提前指定排序规则
    m1.insert(pair<int,int>(1,10));
    m1.insert(pair<int,int>(2,20));
    m1.insert(pair<int,int>(5,50));
    m1.insert(pair<int,int>(3,30));
    m1.insert(pair<int,int>(4,40));
    PrintMap2(m1);

}

int main()
{
    test01();
    return 0;
}