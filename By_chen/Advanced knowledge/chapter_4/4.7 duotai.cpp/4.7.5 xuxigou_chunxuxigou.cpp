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

    虚析构和纯虚析构：
        1.多态使用时，若子类中有属性开辟到 堆区，那么父类指针在释放时无法调用到子类的析构代码
        2.解决方式：将父类中的析构函数改为  虚析构 或  纯虚构函数
        3.虚析构语法：  virtual ~类名(){}
          纯虚析构语法： virtual ~类名()=0;
                类外：  类名::~类名(){}



 
*/

#include <iostream>
#include <string>
using namespace std;

class Animal
{
    public:
        Animal()
        {
            cout<<"Animal构造函数的调用！"<<endl;
        }
        virtual void speak()=0;                      //纯虚函数
        // virtual ~Animal()                         //解决方案1，利用虚析构函数，解决父类指针释放子类对象的问题
        // {
        //     cout<<"Animal析构函数的调用！"<<endl;
        // }

        virtual ~Animal()=0;                              //解决方案2，利用纯虚析构函数,但为保证虚构函数释放父类中内存，纯虚函数和虚析构函数都要有具体的函数体,函数体为空也行。
};

Animal::~Animal()
{
     cout<<"Animal纯虚析构函数的调用！"<<endl;
}

class Cat:public Animal
{
    public:
        virtual void speak()                            //重写父类中的纯虚函数
        {
            cout<<*m_Name<<"小猫在说话"<<endl;
        }
        Cat(string name)
        {
            cout<<"Cat构造函数的调用"<<endl;
            m_Name=new string(name);
        }
        ~Cat()
        {
            if (this->m_Name!=NULL)
            {
                cout<<"Cat析构函数的调用！"<<endl;         
                delete m_Name;
                m_Name=NULL;
            }
        }
    public:
        string *m_Name;
};

void test01()
{
        Animal *animal=new Cat("Tom");                 //父类指针指向子类对象
        animal->speak();
        delete animal;
}

int main()
{
    test01();

    system("pause");
    return 0;
}

/*
    总结：
        1.虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
        2.如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
        3.拥有 纯虚析构函数 的类也属于抽象类


*/

