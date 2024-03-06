//运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
//加号（+）运算符重载，实现两个自定义数据类型的相加运算

//左移运算符重载：可以输出自定义数据类型

//递增运算符作用：通过重载递增运算符，实现自己的整形数据

//赋值运算符重载：
    //C++编译器至少给一个类添加4个函数
        //1.默认构造函数（无参，函数体为空）
        //2.默认析构函数（无参，函数体为空）
        //3.默认拷贝构造函数，对属性进行值拷贝
        //4.赋值运算符operator=，对属性进行值拷贝
        //前三个已经学过

    //如果类中有属性指向堆区，赋值操作时也会出现深浅拷贝的问题

#include<iostream>                             //iostream：input/output stream  输入输出流库     cout是标准输出流对象
#include<string>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        m_Age=new int(age);
    }


    ~Person()                                   //简单赋值操作内存地址被赋值，析构时堆区内容指向同一块内存，被重复释放，程序崩溃，需要重载赋值运算符
    {
        if(m_Age!=NULL)
        {
            delete m_Age;
            m_Age=NULL;
        }
    } 

    //重载赋值运算符
    Person &operator=(Person &p)
    {
        if(m_Age!=NULL)
        {
            delete m_Age;
            m_Age=NULL;
        }

        // m_Age=p.m_Age;              //编译器提供的浅拷贝
        m_Age=new int(*p.m_Age);       //提供深拷贝

        return *this;                   //返回自身（该返回值的函数类型是指针解引用，不能用void）
    }
    int *m_Age;
};

void test01()
{
    Person p1(18);
    Person p2(28);
    Person p3(38);
    p3=p2=p1;

    cout<<"P1="<<*p1.m_Age<<endl;
    cout<<"P2="<<*p2.m_Age<<endl;
    cout<<"P3="<<*p3.m_Age<<endl;

}

void test02()
{
    int a=12;
    int b=14;
    int c=16;

    a=b=c;                              //正常函数内可以连续赋值，不报错
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
    cout<<"c="<<c<<endl;
}
int main() {

	test01();
    // test02();


	system("pause");

	return 0;
}



//总结：重载运算符配合友元可以实现输出自定义数据类型。