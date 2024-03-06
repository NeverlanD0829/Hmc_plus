#include <iostream>
using namespace std;

int main()
{
    //short(2)<int(4)<=long(4)<long long(8)    long在win下是4位，在linux下是8位    
    //可以利用sizeof（）求出数据类型
    //语法：sizeof(数据类型/变量)

    short num1=10;
    cout<<"short占用的内存空间为："<<sizeof(short)<<endl;

    int num2=89;
    cout<<"int占用的内存空间为："<<sizeof(num2)<<endl;

    long num3=5345;
    cout<<"long占用的内存空间为："<<sizeof(num3)<<endl;
    
    long long num4=233;
    cout<<"long long占用的内存空间为："<<sizeof(num4)<<endl;

    system("pause");
    return 0;
}