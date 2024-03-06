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
    3.3.1算数仿函数
        功能：实现四则运算
        仿函数原型：
            template<class T> T plus<T>                 //加法仿函数
            template<class T> T minus<T>                //减法仿函数
            template<class T> T multiplies<T>           //乘法仿函数
            template<class T> T divides<T>              //除法仿函数
            template<class T> T modulus<T>              //取模仿函数
            template<class T> T negate<T>               //取反仿函数

*/
#include <iostream>
#include <functional>
using namespace std;

//template<class T> T negate<T> 取反仿函数（一元仿函数）
void test01()
{
    negate<int> n;
    cout<<n(50)<<endl;                //输出-50
}
void test02()                   //加法仿函数(二元仿函数)
{
    plus<int> p;
    cout<<p(40,4);
}

int main()
{
    test01();
    test02();
}