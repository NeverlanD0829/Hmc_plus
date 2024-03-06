//友元：
    //生活中你的家有客厅(public)和卧室(private)。客厅所有客人都可以进去，但卧室是私有的，也就是说只有你能进去。但是呢，你也可以允许你的好闺蜜，好基友进去。
    //程序里，有些私有属性，也想让类外特殊的一些函数或类进行访问，这就需要用到友元的技术。
    //友元的目的就是让一个函数或者类  访问另一个类中的私有成员。
    //友元关键字为：friend

//友元的三种实现：
    //全局函数做友元
    //类做友元
    //成员函数做友元


//成员变量和成员函数分类储存
    //c++中，类内的成员变量和成员函数分开存储
    //只有  非静态成员变量  才属于类的对象上。



#include<iostream>
#include<string>
using namespace std;

class Building;
//建筑物类
class GoodGay
{
public:
    GoodGay();
    void visit();                                //参观函数，让visit函数可以访问Building中私有成员
    void visit2();                               //让visit2()函数不可以访问Building中私有成员
    Building * building;                        //维护Building类的指针，定义了一个名为 building的指针变量，其类型为 Building 类的指针
};

class Building
{
    friend void GoodGay::visit();               //让GoodGay类是Building类的好朋友，使GoodGay类可以访问本类的私有成员。
    friend void GoodGay::visit2(); 
public:
    Building();
    string m_SittingRoom;           //  客厅
private:
    string m_BedRoom;               //卧室 
};

//类外写成员函数
Building::Building()
{
    m_SittingRoom="客厅";
    m_BedRoom="卧室";
}

GoodGay::GoodGay()
{
    //创建建筑物对象
    building=new Building;

}

void GoodGay::visit()
{
    cout<<"好基友类正在访问："<<building->m_SittingRoom<<endl;
    cout<<"好基友类正在访问："<<building->m_BedRoom<<endl;                  //私有属性不可访问      类做友元。
} 
void GoodGay::visit2()
{
    cout<<"visit2()好基友类正在访问："<<building->m_SittingRoom<<endl;
    cout<<"visit2()好基友类正在访问："<<building->m_BedRoom<<endl;          //私有属性不可访问      类做友元。
} 

void test01()
{
    GoodGay gg;
    gg.visit();
    gg.visit2();
}

int main()
{
    test01();

    system("pause");
    return 0;
}