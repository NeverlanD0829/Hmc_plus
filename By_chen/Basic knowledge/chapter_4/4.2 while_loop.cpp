#include <iostream>
#include <string>
using namespace std;



//语法 ：   while(循环条件){循环语句}

//循环条件为真，则执行循环语句,在执行循环语句时候，程序必须提供跳出循环的出口，否则出现死循环




int main() 
{

    int num=0;
    while(num<10)
    {
        cout<<"num="<<num<<endl;
        num++;
    }

	system("pause");
	return 0;
}
 