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

*/
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

//template<class T> bool greater<T>   大于
class MyCompare
{
    public:
        bool operator()(int v1,int v2)
        {
            return v1>v2;
        }
};

void test01()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(60);
    v.push_back(0);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    sort(v.begin(),v.end(),MyCompare());                    //自己实现的排序
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    sort(v.begin(),v.end(),greater<int>());                 //内建的函数对象
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main()
{
    test01();
}