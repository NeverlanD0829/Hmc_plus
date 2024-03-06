//引用的作用
    //给变量起别名
    //语法：   数据类型  &别名=原名； 



#include<iostream>
#include<string>
using namespace std;


int main()
{
    int a=10;
    int &b=a;                   

    cout<<"a的值为："<<a<<endl;
    cout<<"b的值为："<<b<<endl;

    b=100;
    cout<<"a的值为："<<a<<endl;
    cout<<"b的值为："<<b<<endl;

    system("pause");
    return 0;
}