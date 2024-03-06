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


#include<iostream>
using namespace std;

class Person
{
    public:
        int m_Age;
        Person()                                    //构造函数，函数名称与类名相同
        {
            cout<<"默认无参构造函数的调用"<<endl;
        }

        Person(int age)                          
        {
            m_Age=age;
            cout<<"默认有参构造函数的调用"<<endl;
        }

        //拷贝构造函数
        Person(const Person& p)                      //不能把本身的Person p修改掉。因此需加const，以引用的方式传进来
        {
            m_Age=p.m_Age;
            cout<<"拷贝构造函数！"<<endl;
        }

        ~Person()                                    //析构函数，对象销毁前会自动调用析构，无需手动调用，且只会调用一次
        {
            cout<<"Person 析构函数的调用"<<endl;
        }  
};



void test01()                                   //最常用的调用方法，使用一个已经创建完毕的对象来初始化一个新对象
{
    Person p1(20);
    Person p2(p1);
}

void doWork(Person p)                           //值传递的方式给函数参数传值
{

}

void test02()                                   //值传递的方式给函数参数传值
{
    Person p;
    doWork(p);
}



Person doWork2()                                  //值传递的方式给函数参数传值
{
    Person p1;                                      //这一行的Person p1与89行的Person p1地址不一样，89行的是拷贝后的地址。
    cout<<"doWork2() 返回地址："<<(int *)&p1<<endl;         
    return Person(p1);                                  
}                                                //以值方式返回局部对象

void test03()                                   //值传递的方式给函数参数传值
{
    Person p=doWork2();
    cout<<"test03返回地址："<<(int *)&p<<endl;

}


int main()
{
    // test01();
    // test02();                                     //实参传递给形参，拷贝出一个新的临时数据
    test03();                                     //拷贝出一个新的对象传递给test03.
    system("pause");
    return 0;
}