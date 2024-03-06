/*
    多态是C++面向对象三大特性之一。
    分类：
        静态多态：函数重载、运算符重载属于静态多态，复用函数名。
        动态多态：派生类（子类）、虚函数实现运行时多态
    区别：
        1、静态多态的函数地址 早绑定(编译阶段确定函数地址)
        2、动态多态的函数地址 晚绑定(运行阶段确定函数地址)
        函数重写的概念：函数返回值类型、函数名、参数列表完全相等。重写时virtual关键字可写可不写。

    多态类案例：计算器类
        描述：分别利用普通写法和多态写法，设计实现两个操作数进行运算的计算器类。
        多态优点：1.代码组织结构清晰
                 2.可读性强
                 3.利用前期和后期的扩展及维护



 
*/

#include <iostream>
#include <string>
using namespace std;

//普通实现：
// class Calculator
// {
// public:
//     int getResult(string oper)
//     {
//         if (oper=="+")
//         {
//             return m_Num1+m_Num2;
//         }
//         else if(oper=="-")
//         {
//             return m_Num1-m_Num2;
//         }
//         else if(oper=="*")
//         {
//             return m_Num1*m_Num2;
//         }
//     }
// public:
//     int m_Num1;
//     int m_Num2;
// };


// void test01()
// {
//     Calculator c;
//     c.m_Num1=10;
//     c.m_Num2=20;

//     cout<<c.m_Num1<<"+"<<c.m_Num2<<"="<<c.getResult("+")<<endl;
//     cout<<c.m_Num1<<"-"<<c.m_Num2<<"="<<c.getResult("-")<<endl;
//     cout<<c.m_Num1<<"*"<<c.m_Num2<<"="<<c.getResult("*")<<endl;
// }



//多态实现
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }

    int m_Num1;
    int m_Num2;

};


class AddCalculator:public AbstractCalculator
{
    public:
        int getResult()
        {
            return m_Num1+m_Num2;
        }
};

class SubCalculator:public AbstractCalculator
{
    public:
        int getResult()
        {
            return m_Num1-m_Num2;
        }
};

class MulCalculator:public AbstractCalculator
{
    public:
        int getResult()
        {
            return m_Num1*m_Num2;
        }
};


void test02()
{
    //创建加法计算器
    AbstractCalculator *abc=new AddCalculator;                  //多态的使用，用父类指针指向子类对象。
    abc->m_Num1=10;
    abc->m_Num2=10;
    cout<<abc->m_Num1<<"+"<<abc->m_Num2<<"="<<abc->getResult()<<endl;
    delete abc;
    
    //创建减法计算器
    abc=new SubCalculator;
    abc->m_Num1=10;
    abc->m_Num2=10;
    cout<<abc->m_Num1<<"-"<<abc->m_Num2<<"="<<abc->getResult()<<endl;
    delete abc;

    //创建乘法计算器
    abc=new MulCalculator;
    abc->m_Num1=10;
    abc->m_Num2=10;
    cout<<abc->m_Num1<<"*"<<abc->m_Num2<<"="<<abc->getResult()<<endl;
    delete abc;
}

int main()
{
    //test01();
    test02();

    system("pause");
    return 0;
}


/*
多态优点：1.代码组织结构清晰
         2.可读性强
         3.利用前期和后期的扩展及维护


*/
