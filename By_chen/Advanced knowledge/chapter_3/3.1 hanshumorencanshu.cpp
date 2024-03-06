//3.1 函数的默认参数
    //c++中，函数的形参列表中的参数是可以有默认值的
    //语法： 返回值类型   函数名 （参数=默认值）{}
    //用法：如果自己传入数据就用自己的，如果没有就用默认值。




#include<iostream>
using namespace std;


// int func(int a,int b=10,int c)              错误，默认值必须放在右边，如果某个位置参数有默认值，则从这个位置往后，从左到右都必须要有默认值。            
// {
//     return a+b+c;
// }




// int func(int a,int b=10,int c=10)           如果函数申明有默认值，则函数实现的时候就不能有默认参数。     
// int func(int a,int b,int c)                   
// {
//     return a+b+c;
// }



int func(int a, int b=100,int c=10)                   
{
    return a+b+c;
}



int main()
{
    int a=20;
    int b=10;
    int c=9;
    int d=func(a,b,c);
    cout<<"d输出值为："<<d<<endl;


    int e=func(10,20);
    cout<<"e输出值为："<<e<<endl;


    system("pause");
    return 0;
}



//注意：
    //默认值必须放在右边。
    //声明和实现，有且只能有一个有默认参数。否则可能出现二义。