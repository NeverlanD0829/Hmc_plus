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

        
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Greater                                                           //内置数据类型
{
public:
    bool operator()(int val) const                                      //声明该成员函数是常量成员函数
    {
        return val>5;
    }
};
void test01()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it=find_if(v.begin(),v.end(),Greater());      //按条件查找
    if(it==v.end())
    {
        cout<<"找不到"<<endl;
    }
    else
    {
        cout<<"找到了大于5的数字"<<endl;
        cout<<*it<<endl;
    }
}

class Person2                                                       //自定义数据类型比较
{
    public:
        Person2(string name,int age)
        {
            this->m_Name=name;
            this->m_Age=age;
        }
        bool operator==(const Person2& p) 
        {
            if(this->m_Name==p.m_Name && this->m_Age==p.m_Age)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    string m_Name;
    int m_Age;
};
class Greater20
{
public:
    bool operator()(const Person2& p)const
    {
        return p.m_Age>20;
    }
};
void test02()
{
    vector<Person2> v2;
    Person2 p1("A",10);
    Person2 p2("B",17);
    Person2 p3("C",40);
    Person2 p4("D",60);
    v2.push_back(p1);
    v2.push_back(p2);
    v2.push_back(p3);
    v2.push_back(p4);
    vector<Person2>::iterator it=find_if(v2.begin(),v2.end(),Greater20());
    if(it==v2.end())
    {
        cout<<"没有找到！"<<endl;
    }
    else
    {
        cout<<"找到了！"<<endl;
        cout<<"Name:"<<it->m_Name<<"\tAge:"<<it->m_Age<<endl;
    }
}

int main()
{
    // test01();
    test02();
}