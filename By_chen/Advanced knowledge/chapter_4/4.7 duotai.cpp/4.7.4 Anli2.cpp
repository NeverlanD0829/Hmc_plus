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

    纯虚函数和抽象类：
        多态中，通常父类中的虚函数的实现是毫无意义的，主要是调用子类重写的内容。可将纯虚函数改为纯虚函数。
        语法：  virtual 返回值类型  函数名  （参数列表）=0；
        * 当类中有了纯虚函数，这个类称为  抽象类。
        抽象类特点：
            1.无法实例化对象
            2.子类必须重写抽象类中的纯虚函数，否则也属于抽象类

    案例描述：
        饮品制作流程：煮水-冲泡-倒出-加料
        利用多态实现本案例：提供抽象制作饮品基类，提供子类制作咖啡和茶叶



 
*/

#include <iostream>
#include <string>
using namespace std;

class AbstractDrinking
{
    public:
        //烧水
        virtual void Boil()=0;
        //冲泡
        virtual void Brew()=0;
        //导入杯中
        virtual void PourInCup()=0;
        //加入辅料
        virtual void PutSomething()=0;

        //规定流程
        void MakDrink()
        {

            Boil();
            Brew();
            PourInCup();
            PutSomething();
        }
};


//制作咖啡
class Coffee:public AbstractDrinking
{
public:
    //烧水
    virtual void Boil()
    {
        cout<<"煮水"<<endl;
    }

    //冲泡
    virtual void Brew()
    {
        cout<<"冲咖啡液"<<endl;
    }

    //倒杯
    virtual void PourInCup()
    {
        cout<<"倒入杯中"<<endl;
    }
    
    //加料
    virtual void PutSomething()
    {
        cout<<"加糖"<<endl;
    }
};


//制作茶
class tea:public AbstractDrinking
{
public:
    //烧水
    virtual void Boil()
    {
        cout<<"煮水"<<endl;
    }

    //冲泡
    virtual void Brew()
    {
        cout<<"泡茶"<<endl;
    }

    //倒杯
    virtual void PourInCup()
    {
        cout<<"倒入杯中"<<endl;
    }
    
    //加料
    virtual void PutSomething()
    {
        cout<<"加枣"<<endl;
    }
};

//业务函数
void Dowork(AbstractDrinking * drink)              // 接受一个指向 AbstractDrinking 类或其派生类的对象的指针作为参数
{
    drink->MakDrink();
    delete drink;
}


void test01()
{
    Dowork(new Coffee);
    cout<<"____________________"<<endl;
    Dowork(new tea);
}

int main()
{
    test01();

    system("pause");
    return 0;
}



