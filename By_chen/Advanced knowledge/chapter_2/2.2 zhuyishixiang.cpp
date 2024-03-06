//引用的作用
    //给变量起别名
    //语法：   数据类型（与原名同类型） &别名=原名；

//引用的注意事项
    //引用必须初始化
    //一旦初始化就不可以更改了。



#include<iostream>
#include<string>
using namespace std;


int main()
{
    int a=10;
    int &b=a;

    //引用必须初始化

    //int &c;                     //不合法，c需要初始化

    int c=20;
    //引用初始化后不也能改变
    //int &b=c;                   //不合法，b已经是a的别名了，不能再是c的别名。

    cout<<"a的值为："<<a<<endl;
    cout<<"b的值为："<<b<<endl;
    cout<<"c的值为："<<c<<endl;

    system("pause");
    return 0;
}