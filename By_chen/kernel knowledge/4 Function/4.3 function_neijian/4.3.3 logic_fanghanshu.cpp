/*
    内建函数对象意义
    概念：
        STL内建了一些函数对象。
    分类：
        算数仿函数
        关系仿函数
        逻辑仿函数
    用法：
        仿函数产生的对象，用法和一般函数完全相同
        使用内建函数对象，需要引入头文件
            #include <functional>
    4.3.1算数仿函数
        功能：实现四则运算
        仿函数原型：
            template<class T> T plus<T>                 //加法仿函数
            template<class T> T minus<T>                //减法仿函数
            template<class T> T multiplies<T>           //乘法仿函数
            template<class T> T divides<T>              //除法仿函数
            template<class T> T modulus<T>              //取模仿函数
            template<class T> T negate<T>               //取反仿函数
    4.3.2 关系仿函数
        功能：实现关系对比
        仿函数原型：
            template<class T> bool equal_to<T>          //等于
            template<class T> bool not_equal_to<T>      /不等于
            template<class T> bool greater<T>           //大于
            template<class T> bool greater_equal<T>     //大于等于
            template<class T> bool less<T>              //小于
            template<class T> bool less_equal<T>        //小于等于
    4.3.3 逻辑仿函数
        功能：实现逻辑运算
        函数原型：
            template<class T> bool logical_and<T>       //逻辑与
            template<class r> bool logical_or<T>        //逻辑或
            templateclass T> bool logical_not<T>        //逻辑非

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void Print(vector<bool> &v)
{
    for(vector<bool>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test01()
{
    vector<bool>v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);
    Print(v);

    //templateclass T> bool logical_not<T>//逻辑非
    //利用逻辑非，将容器v搬运到容器v2中
    vector<bool>v2;
    v2.resize(v.size());
    transform(v.begin(),v.end(),v2.begin(),logical_not<bool>());
    Print(v2);
}

int main()
{
    test01();
}