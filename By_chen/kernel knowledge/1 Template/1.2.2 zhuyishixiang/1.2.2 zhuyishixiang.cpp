/*
    1.模版
    1.1模版的概念
        建立通用的模具,提高复用性
    1.2函数模版
        作用:建立通用函数,函数返回值类型和形参类型可不具体指定,用虚拟类型代表
        template<typename T>
    1.3函数模版注意事项
        自动类型推导,必须导出一致的数据类型T才可以使用
        模版必须要确定出T的数据类型才可以使用


*/

#include <iostream>
#include <string>
using namespace std;


//函数模版
/*
    声明一个模版,后面代码中的T是一个通用的数据类型,
    class 关键字用于声明一个模板类（Template Class）。这里的 class 不是表示类的实例，而是表示类型参数 T 可以是任何类型
*/
template <class T>               
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
    char c='c';

    MySwap(a,b);
    // MySwap(a,c);            //自动类型推导,必须导出一致的数据类型T才可使用

    cout<<"模版函数中自动类型推导的数值交换a:"<<a<<endl;
    cout<<"模版函数中自动类型推导的数值交换b:"<<b<<endl;
}

//模版必须要确定T的数据类型才可以使用

template <class>
void func()
{
    cout<<"func函数"<<endl;
}

void test02()
{
    // func();                      //错误,没有给出T,模版必须要给指定的数据类型T才可以使用
    func<int>();                    //强行给定一个类型
}

int main()
{

    // test01();
    test02();
}