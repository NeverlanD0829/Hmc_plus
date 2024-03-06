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
        主要技术点：利用仿函数，改变排序规则。   仿函数：重载函数调用运算符（）；
    3.7.8 set自定义数据类型排序
    
*/
#include <iostream>
#include <string>
#include <set>
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

class  PersonCompare
{
    public:
        bool operator()(const Person &p1,const Person &p2)
        {
            return p1.m_Age>p2.m_Age;           //按年龄降序排序
        }
};

void PrintSet(set<Person,PersonCompare> &s)
{
    if(!s.empty())
    {
        for(set<Person,PersonCompare>::const_iterator it=s.begin();it!=s.end();it++)
        {
            cout<<"姓名："<<it->m_Name<<"\t 年龄："<<it->m_Age<<endl;;
        }
    }
    else
    {
        cout<<"set容器为空"<<endl;
    }
    
}

void test01()
{
    set<Person,PersonCompare> s;
    Person p1("刘备",20);
    Person p2("关羽",50);
    Person p3("张飞",70);
    Person p4("赵云",30);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    PrintSet(s);
}

int main()
{
    test01();
    return 0;
}