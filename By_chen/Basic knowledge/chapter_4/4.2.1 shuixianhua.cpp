#include <iostream>
#include <string>
using namespace std;



//语法 ：   while(循环条件){循环语句}
//循环条件为真，则执行循环语句,在执行循环语句时候，程序必须提供跳出循环的出口，否则出现死循环



//案例描述：水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身
//例如：1^3 + 5^3+ 3^3 = 153
//请利用do…while语句，求出所有3位数中的水仙花数

int main() 
{

    int num=100;

    int a=0;
    int b=0;
    int c=0;
    do
    {
        a=num%10;           //个位
        b=num/10%10;        //十位
        c=num/100;          //百位

        if(a*a*a+b*b*b+c*c*c==num)
        {
            cout<<"这个逼数是水仙花数："<<num<<endl;
        }
        num++;
    }
    while(num<10000);

	system("pause");
	return 0;
}