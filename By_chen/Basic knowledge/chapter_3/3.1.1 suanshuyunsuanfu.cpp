#include <iostream>
#include <string>
using namespace std;

//运算符：执行代码的运算。
//包括：算术运算符、赋值运算符、比较运算符、逻辑运算符。




int main()
{
    //加减乘除
 
	int a1 = 10;
	int b1 = 3;
 
	cout << a1 + b1 << endl;
	cout << a1 - b1 << endl;
	cout << a1 * b1 << endl;
	cout << a1 / b1 << endl;  //两个整数相除结果依然是整数
 
	int a2 = 10;
	int b2 = 20;
	cout << a2 / b2 << endl; 
 
	int a3 = 10;
	int b3 = 0;
	//cout << a3 / b3 << endl; //报错，除数不可以为0
 
 
	//两个小数可以相除
	double d1 = 0.5;
	double d2 = 0.25;
	cout << d1 / d2 << endl;
 
    system("pause");
    return 0;
}