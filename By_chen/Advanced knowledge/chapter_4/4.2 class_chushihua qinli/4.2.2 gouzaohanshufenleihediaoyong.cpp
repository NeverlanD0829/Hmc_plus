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


#include<iostream>
using namespace std;

class Person
{
    public:
        int age;
        Person()                                    //构造函数，函数名称与类名相同
        {
            cout<<"Person 的无参构造函数的调用"<<endl;
        }

        Person(int a)                          
        {
            age=a;
            cout<<"Person 的有参构造函数的调用"<<endl;
        }

         //拷贝构造函数
        Person(const Person& p)                      //不能把本身的Person p修改掉。因此需加const，以引用的方式传进来。   拷贝一模一样的数据进来
        {
            age=p.age;
            cout<<"拷贝构造函数！"<<endl;
        }


        ~Person()                                    //析构函数，对象销毁前会自动调用析构，无需手动调用，且只会调用一次
        {
            cout<<"Person 析构函数的调用"<<endl;
        }  
};

    //注意：构造和析构函数都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构。


void test01()
{
    //1、调用（括号法）：  最常用。
    // Person p;                                 //默认构造函数
    // Person p1();                              //栈上的数据，test01执行完后，释放该对象。                   //只创建对象，没有调用构造函数（p后没有括号），但是程序可运行，系统自动调用函数。
    //                                           //注意事项：调用默认构造函数时，不要加（）,否则系统会认为这是函数的申明（void func();   ）。不会认为是创建对象的过程。
    Person p2(10);                            //有参构造函数的调用
    // Person p3(p2);

    // cout<<"p2的年龄为："<<p2.age<<endl;
    // cout<<"p3的年龄为："<<p3.age<<endl;


    //2、显示法：
    // Person p1;                           //默认无参构造
    // Person p2=Person(10);                //有参构造
    // Person p3=Person(p1);                //拷贝构造

    // Person(10);                       //注意事项1：匿名对象，当前执行结束后，系统会立刻回收掉匿名对象，调用析构函数，然后再打印aaaaaa
    // cout<<"aaaaaaa"<<endl;


    //注意事项2：不要利用拷贝构造函数初始化匿名函数。
    //Person(p3);                              //编译器认为Person(p2)==person p2,即编译器会认为这是对象的申明。

    //3、隐式转换法：
    Person p4=10;                           //相当于Person p4=Person(10);  
    Person p5=p2;                           //隐式构造的拷贝构造方法。
}

int main()
{
    //Person p;               //默认构造函数的调用

    test01();

    system("pause");
    return 0;
}