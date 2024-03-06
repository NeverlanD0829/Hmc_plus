//运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
//加号（+）运算符重载，实现两个自定义数据类型的相加运算

//左移运算符重载：可以输出自定义数据类型

#include<iostream>                             //iostream：input/output stream  输入输出流库     cout是标准输出流对象
#include<string>
using namespace std;

 class Person
{
   friend ostream & operator<<(ostream &cout,Person &p);
public:
    Person(int a,int b)
    {
        m_A=a;
        m_B=b;
    }

private:
    //尝试利用成员函数重载  左移运算符，但发现不可行，cout在右侧
    // void operator<<(Person &p)          //p.operator<<(cout)     简化版本：p<<cout,但我们需要   cout<<p
    // {   

    // }

    int m_A;
    int m_B;
 };
 

 //使用全局函数重载左移运算符
ostream & operator<<(ostream &cout,Person &p)                //本质：operator<<(cout,p),简化cout<<p
 {
    cout<<"m_A= "<<p.m_A<<" m_B="<<p.m_B;
    return cout;
 }




void test01()
{
    Person p(10,19);


    cout<<p<<endl   ;           //不知道如何重载出<<

   

}


int main()
{

    test01();

    system("pause");
    return 0;
}

//总结：重载运算符配合友元可以实现输出自定义数据类型。