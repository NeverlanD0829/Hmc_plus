// 作用：将一段经常使用的代码封装起来，减少重复代码
// 一个较大的程序，一般分为若干个程序块，每个模块实现特定的功能。

//函数的定义：函数的定义一般主要有5个步骤：
    // 1、返回值类型：      一个函数可以返回一个值。在函数定义中
    // 2、函数名：          给函数起个名称
    // 3、参数表列:         使用该函数时，传入的数据
    // 4、函数体语句:       花括号内的代码，函数内需要执行的语句
    // 5、return 表达式:    和返回值类型挂钩，函数执行完后，返回相应的数据

//语法：
    // 返回值类型 函数名 （参数列表）
    // {
    //        函数体语句
    //        return表达式
    // }

//所谓值传递，就是函数调用时实参将数值传入给形参
//值传递时，如果形参发生改变，并不会影响实参



#include<iostream>
#include<string>
using namespace std;


void swap(int num1,int num2)          //函数定义，函数定义里小括号内称为形参，函数调用时传入的参数称为实参
{
    cout<<"交换前："<<endl;
    cout<<"num1="<<num1<<endl;
    cout<<"num2="<<num2<<endl;

    int temp=num1;
    num1=num2;
    num2=temp;

    cout<<"交换后："<<endl;
    cout<<"num1="<<num1<<endl;
    cout<<"num2="<<num2<<endl;

}


int main()
{
    int a=100,b=200;
    swap(a,b);

    cout<<"main中的a="<<a<<endl;
    cout<<"main中的b="<<b<<endl;
    
    //a=100,b=200
    //值传递时，形参是修饰不了实参的

    system("pause");
    return 0;
}