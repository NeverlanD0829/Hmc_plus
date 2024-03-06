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


//函数的常见样式：无参无返、有参无返、无参有返、有参有返



#include<iostream>
#include<string>
using namespace std;


void test01()                              //无参无返
{
    //void a=10;                          //无类型不可以创建变量，原因：无法分配内存。
    cout<<"this is test01"<<endl;
    //调用时直接用：   test01（）;
}

void test02(int a)                            //有参无返
{

    cout<<"this is test02"<<endl;
    //调用时直接用：   test01（）;
    cout<<"a="<<a<<endl;
}

int test03()                                    //无参有返
{
    cout << "this is test03 " << endl;
	return 10;
}

int test04(int a,int b)                                    //有参有返
{
    cout << "this is test04 " << endl;
    int sum=a+b;
	return sum;
}



int main()
{
    int a=100,b=200;

    test01();
    test02(a);
    test03();
    int sum=test04(a,b);
    cout << "sum=" <<sum<<endl;

    system("pause");
    return 0;
}