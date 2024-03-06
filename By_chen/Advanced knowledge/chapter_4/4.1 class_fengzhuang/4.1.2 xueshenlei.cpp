//C++面向对象三大特性：封装、继承、多态
    //意义： 1、将属性和行为作为一个整体。(放在一个class里面)
        //  2、将属性和行为加以权限控制。
            //   public公共权限：类内外都可以访问
            //   protected保护权限： 类外不可以访问
            //   private私有权限： 类外不可以访问

    //注意：struct与class的区别：
            // struct默认权限为：共有
            // class默认权限为：私有
    //语法： 
        //class  类名   {访问权限:  属性；行为}

//eg.2设计一个学生类，显示学生姓名和学号。


#include<iostream>
using namespace std;
const double PI=3.14;

class student
{
    //类中属性和行为，统一称为  成员
    //属性：成员属性，成员变量
    //行为：成员函数、成员方法


    public:
    string name;
    string id;

    void setname(string name)
    {
        name=name;
        cout<<"姓名："<<name<<"     ";

    }

    void setid(string id)
    {
        id=id;
        cout<<"学号："<<id<<endl;
    }

    void show()
    {
        cout<<"姓名："<<name<<"     ";
        cout<<"学号："<<id<<endl;
    }
};



int main()
{
    student s1,s2;              //  类的实例化
    // s1.name="橙橙";
    // s1.id="2200343";

    s1.setname("橙橙");
    s1.setid("2200343");




    s2.name="薛薛";
    s2.id="2200342";
    s2.show();

    system("pause");
    return 0;
}