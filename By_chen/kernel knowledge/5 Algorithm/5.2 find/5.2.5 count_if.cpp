/*
    算法主要由头文件：<algorithm>/<functional>/<numeric> 组成
        <algorithm>:所有STL头文件中最大的一个，范围涉及到：比较/交换/查找/遍历/复制/修改等等。
        <numeric>:体积很小，自包括几个在序列上进行简单数学运算的模版函数。
        <functional>:定义一些类模版，用以声明函数对象。
    5.1常用遍历算法
        5.1.1 for_each（遍历容器）
            for_each(iterator beg,iterator end,_func);
                beg:起始迭代器   end：结束迭代器     _func:函数或函数对象

        5.1.2 transform
            将一个容器搬运到另一个容器
            原型：
                transform(iterator beg1,iterator end1,iterator beg2,_func)
            beg1:源容器开始迭代器
            end1:源容器结束迭代器
            beg2:目标容器起始迭代器
            _func:函数或函数对象
    5.2常用查找算法
        5.2.1 find
            find 查找指定元素 找到返回指定元素的迭代器 找不到返回end()迭代器。
        5.2.2 find_if
            find_if 按条件查找，返回迭代器
        5.2.3 adjacent_find   
            查找相邻的重复元素，返回相邻重复元素第一个位置的迭代器
        5.2.4 count
            统计元素个数
            count(begin,end,value)
        5.2.5 count_if
            按条件统计指定元素个数----谓词

        
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Greater2
{
    public:
    bool operator()(int val) const
    {
        return val>14;
    }
};

void test01()                                           //1、内置数据类型
{
    vector<int> v;
    v.push_back(19);
    v.push_back(14);
    v.push_back(17);
    v.push_back(14);
    v.push_back(12);
    v.push_back(17);
    v.push_back(17);
    v.push_back(17);
    sort(v.begin(),v.end());
    int num=count_if(v.begin(),v.end(),Greater2());        //按条件查找
    cout<<"个数为："<<num<<endl;
}

class Person                                               //2、自定义数据类型
{
    public:
    Person(string name,int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }
    bool operator==(const Person &p)
    {
        if(this->m_Age==p.m_Age)
        {
            return true;
        }
        else{
            return false;
        }
    }
    string m_Name;
    int m_Age;
};
class Greater3
{
public:
    bool operator()(Person &p) 
    {
        return p.m_Age>14;
    }
};

void test02()
{
    vector<Person> v;
    Person p1("A",10);
    Person p2("B",12);
    Person p3("C",14);
    Person p4("D",16);
    Person p5("E",18);
    Person p6("D",16);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);
    int num=count_if(v.begin(),v.end(),Greater3());         //按照条件查找
    cout<<num<<endl;

}

int main()
{
    // test01();
    test02();
}