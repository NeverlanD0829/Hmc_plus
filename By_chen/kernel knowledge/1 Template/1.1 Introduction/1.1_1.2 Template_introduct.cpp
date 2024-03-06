/*
    1.模版
    1.1模版的概念
        建立通用的模具,提高复用性
    1.2函数模版
        作用:建立通用函数,函数返回值类型和形参类型可不具体指定,用虚拟类型代表
        template<typename T>


*/

#include <iostream>
#include <string>
using namespace std;

//整形交换
void SwapInt(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

//交换浮点型
void SwapDouble(double &a,double &b)
{
    double temp=a;
    a=b;
    b=temp;
}

//函数模版
template <typename T>               //声明一个模版,后面代码中的T是一个通用的数据类型
void MySwap(T &a,T &b)
{
    T tmp=a;
    a=b;
    b=tmp;
}



void test01()
{
    int a=10;
    int b=20;
    SwapInt(a,b);
    cout<<"普通函数中整形的数值交换a:"<<a<<endl;
    cout<<"普通函数中整形的数值交换b:"<<b<<endl;

    double c=3.3;
    double d=2.5;

    SwapDouble(c,d);
    cout<<c<<endl;
    cout<<d<<endl;
    cout<<"普通函数中浮点型的数值交换c:"<<c<<endl;
    cout<<"普通函数中浮点型的数值交换d:"<<d<<endl;
}
void test02()
{
    int a=10;
    int b=20;

    double c=10.3;
    double d=20.5;
    
    //两种使用模版的方法
    //1.自动类型推倒
    MySwap(a,b);
    cout<<"模版函数中自动类型推导的数值交换a:"<<a<<endl;
    cout<<"模版函数中自动类型推导的数值交换b:"<<b<<endl;
    
    //1.自动类型推倒
    MySwap(c,d);
    cout<<"模版函数中自动类型推导的数值交换c:"<<c<<endl;
    cout<<"模版函数中自动类型推导的数值交换d:"<<d<<endl;

    //2.显示指定类型
    MySwap<double>(c,d);
    cout<<"模版函数中自动类型推导的数值交换c:"<<c<<endl;
    cout<<"模版函数中自动类型推导的数值交换d:"<<d<<endl;
}



int main()
{

    // test01();
    test02();
}