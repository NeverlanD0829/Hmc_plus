/*
宏常量：#define 常量名  常量值

const修改的变量：#const 数据类型 常量名 = 常量值

*/

#define day 7
#include <iostream>
using namespace std;

int main()
{
	// day=14;  day是常量，不可修改，修改后即报错
    
    const int month=12;
    //month=24;                 错误，const修饰的变量也是常量

    cout <<"一年里总共有" << month <<"月" << endl;  
    system("pause"); 
	return 0;
}
