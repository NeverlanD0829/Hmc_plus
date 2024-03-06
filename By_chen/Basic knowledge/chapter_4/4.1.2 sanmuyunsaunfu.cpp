//C/C++支持最基本的三种程序运行结构：顺序结构、选择结构、循环结构
//顺序结构：程序按顺序执行，不发生跳转
//选择结构：依据条件是否满足，有选择的执行相应功能
//循环结构：依据条件是否满足，循环多次执行某段代码

#include <iostream>
#include <string>
#include <windowS.h>
using namespace std;


//三目运算符,与if语句相比，短小简洁，但缺点是如果用于嵌套的话，结构会不清晰。
//语法：   表达式1？表达式2：表达式3

//如果表达式1的值为真，执行表达式2，并返回表达式2的结果；
//如果表达式1的值为假，执行表达式3，并返回表达式3的结果。


int main() 
{
    //输入一个分数，如果大于600，则视为考上一本大学；
    SetConsoleOutputCP(CP_UTF8);
    int a=10;
    int b=20;
    int c=0;
   
    c=a>b?a:b;
    cout<<"c的值为："<<c<<endl;

    //C++中，三目运算符返回的是变量，可以继续赋值。

    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    cout<<"c="<<c<<endl;



	system("pause");
	return 0;
}
 