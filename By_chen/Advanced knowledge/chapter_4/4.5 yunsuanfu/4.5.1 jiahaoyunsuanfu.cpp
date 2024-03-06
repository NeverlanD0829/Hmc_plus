//运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
//加号（+）运算符重载，实现两个自定义数据类型的相加运算

#include<iostream>
#include<string>
using namespace std;

 class Person
{
 public:
    Person()
    {

    }
    Person(int a,int b)
    {
        this->m_A=a;
        this->m_B=b;
    }

    //成员函数实现  +号运算符重载                   
    // Person operator+(Person&p)
    // {
    //     Person temp;
    //     temp.m_A=this->m_A+p.m_A;
    //     temp.m_B=this->m_B+p.m_B;
    //     return temp;
    // }

public:
    int m_A;
    int m_B;
 };
 

//全局函数实现  +  号运算符重载
    // Person operator+(Person& p1,Person &p2)
    // {
    //     Person temp(0,0);
    //     temp.m_A=p1.m_A+p2.m_A;
    //     temp.m_B=p1.m_B+p2.m_B;
    //     return temp;
    // }


//运算符重载也可以发生函数重载

Person operator+(Person &p2,int val)
{
    Person temp;
    temp.m_A=p2.m_A+val;
    temp.m_B=p2.m_B+val;
    return temp;
}

void test01()
{
    Person p1;
    p1.m_A=10;
    p1.m_B=10;
    Person p2;
    p2.m_A=20;
    p2.m_B=20;

    // Person p3=p1+p2;            //成员函数方式，相当于 p1.operator+(p2)      //全局函数方式相当于operator+(p1，p2)；
    // cout<<"p3.m_A="<<p3.m_A<<"  p3.m_B="<<p3.m_B<<endl;

    Person p3=p2+10;              
    cout<<"p3.m_A="<<p3.m_A<<"  p3.m_B="<<p3.m_B<<endl;

}


int main()
{

    test01();

    system("pause");
    return 0;
}

//总结：1.对内置的数据类型的表达式的运算符是不可能改变的;   2.不要滥用运算符重载。
