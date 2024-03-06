#include <iostream>
#include <string>
using namespace std;

//运算符：执行代码的运算。
//包括：算术运算符、赋值运算符、比较运算符、逻辑运算符。




int main() {
 
	//赋值运算符
 
	// =
	int a = 10;
	a = 100;
	cout << "a = " << a << endl;
 
	// +=
	a = 10;
	a += 2; // a = a + 2;
	cout << "a = " << a << endl;
 
	// -=
	a = 10;
	a -= 2; // a = a - 2
	cout << "a = " << a << endl;
 
	// *=
	a = 10;
	a *= 2; // a = a * 2
	cout << "a = " << a << endl;
 
	// /=
	a = 10;
	a /= 2;  // a = a / 2;
	cout << "a = " << a << endl;
 
	// %=
	a = 10;
	a %= 2;  // a = a % 2;
	cout << "a = " << a << endl;
 
	system("pause");
 
	return 0;
}