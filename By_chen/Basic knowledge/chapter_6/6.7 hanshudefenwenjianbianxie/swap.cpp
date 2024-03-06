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


//函数分文件编写一般有4个步骤:
    // 创建后缀名为.h的头文件
    // 创建后缀名为.cpp的源文件
    // 在头文件中写函数的声明
    // 在源文件中写函数的定义

#include"swap.h"


void swap(int a,int b)
{
    int temp = a;
	a = b;
	b = temp;
    cout<<"交换后a,b的值为："<<a<<" ";
    cout<<b<<endl;
}

int main() 
{
 
	int a = 100;
	int b = 200;
    cout<<"交换前a,b的值为："<<a<<" ";
    cout<<b<<endl;
	swap(a, b);
	system("pause");
	return 0;
}
 
