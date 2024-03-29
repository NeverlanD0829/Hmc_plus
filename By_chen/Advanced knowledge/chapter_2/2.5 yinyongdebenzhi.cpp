//引用的作用
    //给变量起别名
    //语法：   数据类型（与原名同类型） &别名=原名；

//引用的注意事项
    //引用必须初始化
    //一旦初始化就不可以更改了。

//引用做函数参数
    //作用：函数传参时，可利用引用的技术让形参修饰实参。
    //优点：可以简化指针修改实参

//引用函数返回值（返回值类型可以使引用）
    //作用：引用可以作为函数的返回值存在的
    //注意：不要返回局部变量引用
    //用法：函数调用作为左值

//引用的本质：
    //在c++内部实现是一个指针常量。

#include<iostream>
#include<string>
using namespace std;


//发现是引用，转换为 int * const ref=&a;
void func(int& ref)
{
    ref=20;                         //ref是引用，转换为  *ref=20；   
}


int main()
{
    int a=10;

    int& ref=a;                     //自动转换为 int * const ref=&a; 指针常量是指针指向不可改，这也说明为什么引用不可更改。
    ref=100;                        //内部发现ref是引用，自动转换为： *ref=20；


    cout<<"a:"<<a<<endl;
    cout<<"ref:"<<ref<<endl;

    func(a);
    cout<<"ref:"<<ref<<endl;

    

    system("pause");
    return 0;
}


//结论：c++推荐使用引用技术，因为语法方便。引用的本质是指针常量，但所有的指针操作编译器都帮我们做了。