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


//建筑物类
class Building
{
    friend void goodGay(Building *building);                                     //goodGay()全局函数是Building的好朋友，可以访问 Building中私有成员。
public:
    string m_SittingRoom;           //  客厅
    Building()
    {
        m_SittingRoom="客厅";
        m_BedRoom="卧室";
    }

private:
    string m_BedRoom;               //卧室 
};

void goodGay(Building *building)
{
    cout<<"好基友的全局函数 正在访问："<<building->m_SittingRoom<<endl;             //客厅是公共属性，在类外依然可以访问。
    cout<<"好基友的全局函数 正在访问："<<building->m_BedRoom<<endl;                 //私有属性不可以访问      想要访问，则需在class中申明函数，并在之前加上  friend 标识。
}  

void test01()
{
    Building building;          //实例化building对象
    goodGay(&building);
}

int main()
{
    test01();

    system("pause");
    return 0;
}