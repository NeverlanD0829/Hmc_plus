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
	cout << 10%3 << endl;
	
    int a2=10;
    int b2=20;
    cout<<a2%b2<<endl;
     
    int a3=10;
    int b3=0;
    //cout<<a3%b3<<endl;

    //两个小数不可以取模,只有整型变量可以取模
    double d1=3.14;
    double d2=1.1;
    //cout<<d1%d2<<endl;

 
    system("pause");
    return 0;
}