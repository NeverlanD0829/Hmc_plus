#include <iostream>
#include <string>
using namespace std;

//运算符：执行代码的运算。
//包括：算术运算符、赋值运算符、比较运算符、逻辑运算符。

//  !	非	!a	如果a为假，则!a为真； 如果a为真，则!a为假。
//  &&	与	a && b	如果a和b都为真，则结果为真，否则为假。
//  ||	或	a || b	如果a和b有一个为真，则结果为真，二者都为假时，结果为假。


int main() {
 
	int a = 10;                         //非0为真
	int b = 10;
	cout << (a && b) << endl;           // 1    
 

	a = 10;
	b = 0;
	cout << (a && b) << endl;           // 0 
 

	a = 0;
	b = 0;
	cout << (a && b) << endl;           // 0
 
	system("pause");
 
	return 0;
}
 