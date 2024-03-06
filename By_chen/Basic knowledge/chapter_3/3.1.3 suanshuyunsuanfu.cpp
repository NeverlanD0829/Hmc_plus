#include <iostream>
#include <string>
using namespace std;

//运算符：执行代码的运算。
//包括：算术运算符、赋值运算符、比较运算符、逻辑运算符。




int main()
{
    //前置递增先对变量进行++，再计算表达式;
    //后置递增先计算表达式，后对变量进行++；
    int a1=10;
    int b=++a1*10;
    cout<<"b="<<b<<endl;
    cout<<"a="<<a1<<endl;

    int a2=10;
    int c=a2++*10;
    cout<<"c="<<c<<endl;
    cout<<"a="<<a2<<endl;


 
    system("pause");
    return 0;
}