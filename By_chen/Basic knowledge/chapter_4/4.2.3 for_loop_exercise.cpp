#include <iostream>
#include <string>
using namespace std;



//语法 ：   for(起始表达式;条件表达式;末尾循环体) { 循环语句; }

//案例描述：从1开始数到数字100， 如果数字个位含有7，或者数字十位含有7，或者该数字是7的倍数，我们打印敲桌子，其余数字直接打印输出。




int main() 
{
    for (int i=1;i<=100;i++)
    {   
        int a,b=0;
        a=i%10;     //个位数
        b=i/10;     //十位数
        if(a==7 || b==7 || i%7==0)
        {
            cout<<"敲桌子！！！"<<endl;
        }
        else
        {
            cout<<i<<endl;
        }
    }
	system("pause");
	return 0;
}
  