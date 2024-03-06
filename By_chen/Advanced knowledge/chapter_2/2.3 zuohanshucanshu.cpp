//引用的作用
    //给变量起别名
    //语法：   数据类型（与原名同类型） &别名=原名；

//引用的注意事项
    //引用必须初始化
    //一旦初始化就不可以更改了。

//引用做函数参数
    //作用：函数传参时，可利用引用的技术让形参修饰实参。
    //优点：可以简化指针修改实参

#include<iostream>
#include<string>
using namespace std;


//交换值得函数
//值传递
void swap1(int a,int b)
{
    int temp=a;
    a=b;
    b=temp;
}

//地址传递
void swap2(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

//引用传递
void swap3(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

int main()
{
    int a=10;
    int b=20;
    swap1(a,b);
    cout<<"值传递后a的值为："<<a<<endl;
    cout<<"值传递后b的值为："<<b<<endl;
    cout<<endl;
    swap2(&a,&b);
    cout<<"值传递后a的值为："<<a<<endl;
    cout<<"值传递后b的值为："<<b<<endl;
    cout<<endl;
    swap3(a,b);
    cout<<"引用传递后a的值为："<<a<<endl;
    cout<<"引用传递后b的值为："<<b<<endl;


    system("pause");
    return 0;
}