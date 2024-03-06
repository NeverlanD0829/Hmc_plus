//3.1 函数的默认参数
    //c++中，函数的形参列表中的参数是可以有默认值的
    //语法： 返回值类型   函数名 （参数=默认值）{}
    //用法：如果自己传入数据就用自己的，如果没有就用默认值。


//3.2 函数占位参数
    //作用：c++中函数的形参列表里可以有占位参数，用来做占位，调佣函数时必须填补该位置。
    //语法：返回类型 函数名 （数据类型） {}



//3.3 函数重载
    //作用：函数名可以相同，提高复用性
    //函数重载满足条件：
        //同一个作用域下；    函数名称相同；        //函数参数  类型不同，或  个数不同，或  顺序不同


    //注意：函数返回值不作为参数重载的条件.

    //注意事项：
        //引用作为重载条件。
        //函数重载碰到函数默认参数。



#include<iostream>
using namespace std;




void func(int &a)
{          
    cout<<"void func(int &a)的重载"<<endl;
}


void func(const int &a)
{          
    cout<<"void func(const int &a)的重载"<<endl;
}

void func2(int a,int b=10)
{          
    cout<<"void func2(int a)的重载"<<endl;
}


void func2(int b)
{          
    cout<<"void func2(int b)的重载"<<endl;
}



int main()
{
    int a=10;
    int b=100;
    func(a);                //调用 func(int &a)
    func(10);                //调用 func(const int &a=10)，合法语法。        如果调用void func(int &a)，则int &a=10，引用不合法。

    //func2(10)             //函数重载碰到默认参数，出现二义性，报错，尽量避免。因此，写函数重载时尽量不要写默认参数。  不知道要调用那个函数。
    func2(a,b);               
    system("pause");
    return 0;
}



//注意：
    //默认值必须放在右边。
    //声明和实现，有且只能有一个有默认参数。否则可能出现二义。