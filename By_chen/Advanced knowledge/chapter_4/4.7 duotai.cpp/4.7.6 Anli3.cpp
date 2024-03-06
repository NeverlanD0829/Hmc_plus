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
    
    多态案例-电脑组装：
        电脑主要部件：CPU/显卡/内存条
        将每个零件封装出抽象基类，提供不同的厂商生产不同的零件。如 Inter厂商和Lenovo产商，创建电脑类提供让电脑工作的函数，调用每个零件工作的接口，测试时组装三台不同的电脑进行工作。



 
*/

#include <iostream>
#include <string>
using namespace std;

//抽象CPU类
class CPU
{
    public:
        virtual void calculate()=0;
};

//抽象显卡类
class Videocard
{
    public:
        virtual void display()=0;
};

//抽象内存条类
class Memory
{
    public:
        virtual void storage()=0;
};

//电脑类
class Computer
{
    public:
        Computer(CPU *cpu,Videocard *vc,Memory *mem)        //构造函数 Computer 接受了指向 CPU、VideoCard 和 Memory 对象的 指针 作为参数，并将它们分别存储在 m_cpu、m_vc 和 m_mem 成员变量中。
        {
            m_cpu=cpu;
            m_vc=vc;
            m_mem=mem;
        }
        void work()                                         //它调用了 CPU、VideoCard 和 Memory 对象的接口（假设这些类中有相应的方法）来进行计算、显示和存储操作。
        {
            //调用接口，让零件工作起来
            m_cpu->calculate();

            m_vc->display();

            m_mem->storage();
        }

        //析构函数释放3个电脑零件

        ~Computer()                                     //释放内存并将指针置为 NULL，以避免悬挂指针问题。
        {
            //释放CPU零件
            if(m_cpu!=NULL)
            {
                delete m_cpu;
                m_cpu=NULL;
            }

            //释放显卡零件
            if(m_vc!=NULL)
            {
                delete m_vc;
                m_vc=NULL;
            }

             //释放内存零件
            if(m_mem!=NULL)
            {
                delete m_mem;
                m_mem=NULL;
            }
        }
    private:
        CPU *m_cpu;             //cpu的零件指针
        Videocard *m_vc;        //显卡零件指针
        Memory *m_mem;          //内存条零件指针
};


//厂商
//Inter厂商
class InterCPU:public CPU
{
    public:
        virtual void calculate()
        {
            cout<<"Inter的CPU开始计算了。"<<endl;
        }
};

class IntelVideoCard :public Videocard
{
    public:
        virtual void display()
        {
            cout << "Intel的显卡开始显示了！" << endl;
        }
};

class InterMemory:public Memory
{
    public:
        virtual void storage()
        {
            cout<<"Inter的内存条开始存储了。"<<endl;
        }
};



//Lenovo厂商
class LenovoCPU:public CPU
{
    public:
        virtual void calculate()
        {
            cout<<"Lenovo的CPU开始计算了。"<<endl;
        }
};

class LenovoVideoCard :public Videocard
{
    public:
        virtual void display()
        {
            cout << "Lenovo的显卡开始显示了！" << endl;
        }
};
class LenovoMemory:public Memory
{
    public:
        virtual void storage()
        {
            cout<<"Lenovo的内存条开始存储了。"<<endl;
        }
};

void test01()
{
    //第一台电脑零件
    CPU *intercpu=new InterCPU;                             //CPU类对象的实例化，堆区创建一个 InterCPU 类型的对象,并将指针 intercpu 指向该地址
    Videocard * intercard=new IntelVideoCard;
    Memory * intermemory=new InterMemory;

    cout<<"第一台电脑开始工作："<<endl;
    //创建第一台电脑
    Computer *Computer1=new Computer(intercpu,intercard,intermemory);
    Computer1->work();
    delete Computer1;

    cout<<"-------------------------------"<<endl;
    cout<<"第二台电脑开始工作："<<endl;
    //第二台电脑组装
    Computer *Computer2=new Computer(new LenovoCPU,new LenovoVideoCard,new LenovoMemory);
    Computer2->work();
    delete Computer2;
                                                                                                                                                                                                                                                                                                                                                                                                                                         
    cout<<"-------------------------------"<<endl;
    cout<<"第三台电脑开始工作："<<endl;
    Computer *Computer3=new Computer(new LenovoCPU,new IntelVideoCard,new LenovoMemory);
    Computer3->work();
    delete Computer3;

}

 

int main()
{

    test01();

    system("pause");
    return 0;
}