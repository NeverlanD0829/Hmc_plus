// C++利用构造函数和析构函数解决了对象的初始化和清理。
//对象的初始化和清理工作是编译器强制要求我们做的事情，因此就算我们不提供构造(初始化)和析构（清理），编译器也会提供，只不过编译器提供的是构造函数和析构函数的空实现。

//构造函数（创建对象时为对象的成员属性赋值）：    类名（）{}
    //1、构造函数没有返回值，也不写void；
    //2、函数名称与类名相同；
    //3、构造函数可以有参数，因此可以发生重载；
    //4、程序在调用对象会自动调用构造，无需手动调用，且只会调用一次。



//析构函数（作用在对象销毁前系统自动调用，执行清理作用）：    ~ 类名（）{}          每调用一次构造函数，就会调用一次析构函数。
    //1、构造函数没有返回值，也不写void；
    //2、函数名称与类名相同，在名称前加上~；
    //3、析构函数不可以有参数，不可以发生重载；
    //4、程序在对象销毁前会自动调用析构，无需手动调用，且只会调用一次。

//两种分类方式：
    //按参数分：有参构造和无参构造
    //按类型分：普通构造和拷贝构造

//三种调用方式：
    //括号法
    //显示法
    //隐式转换法

//拷贝构造函数调用时机分以下三种情况：
    //使用一个已经创建完毕的对象来初始化一个新对象
    //值传递的方式给函数参数传值
    //以值方式返回局部对象

//构造函数调用规则（默认情况下，c++编译器至少给一个类添加三个函数）：
    //默认构造函数(无参，函数体为空)
    //默认析构函数（无参，函数体为空）
    //默认拷贝构造函数，对属性进行值拷贝。

    //规则：如果用户定义有参构造函数，c++不再提供默认无参构造，但会提供默认拷贝构造。
        //如果用户定义拷贝构造函数，c++不会再提供其他构造函数。

//深拷贝与浅拷贝：
    //浅拷贝：简单的赋值拷贝操作(浅拷贝带来问题：堆区内存重复释放——非法操作。！！   解决方法：编译器生成的浅拷贝使出现内存重复释放，因此采用深拷贝，深拷贝函数重新申请内存，解决该问题。)
    //深拷贝：在堆区重新申请空间，进行拷贝操作。

//初始化列表：
    //语法：构造函数():属性1（值1），属性2（值2）......{}

//类对象做类成员：
    //c++中成员可以是另一个类的对象，称该成员为  对象成员。
    //例如：
        // class A{}
        // claSS B
        // {
        //     A a;
        // }
    //B中有对象A作为成员，A为对象成员。
    //思考：当创建B对象时，A与B的构造和析构的顺序谁先谁后？？

//静态成员：
    //静态成员就是在成员变量和成员函数前加上关键字  static
    //静态成员分为：
        //静态成员变量：
            //所有对象共享同一份数据
            //在编译阶段分配内存(全局区)
            //类内声明，类外初始化                      

        //静态成员函数：
            //所有对象共享同一个函数
            //静态成员函数只能访问静态成员变量。

#include<iostream>
#include<string>
using namespace std;


class Person
{
public:
    //静态成员变量：
        //所有对象共享同一份数据
        //在编译阶段分配内存
        //类内声明，类外初始化
    static int m_A;                     //类内声明

private:
    static int m_B;                    //静态成员变量也有访问权限。
  

};

int Person::m_A=100;                    //类外初始化,static就不需要了    ：：是作用域运算符
int Person::m_B=200;

// void test01()                       
// {
//     Person p;
//     cout<<p.m_A<<endl;

//     Person p2;
//     p2.m_A=200;
//     cout<<p.m_A<<endl;
// }


void test02()                                   //静态成员变量不属于某个对象上，因为所有对象都共享同一份数据。
{
    //1.通过对象进行访问；
    // Person p;
    // cout<<p.m_A<<endl;

    //2.通过类名进行访问；
    cout<<Person::m_A<<endl;
    //cout<<Person::m_B<<endl;                   //类外访问不到静态成员私有变量，因此会报错
}


int main()
{
    test01();
    // test02();      


    system("pause");
    return 0;
}