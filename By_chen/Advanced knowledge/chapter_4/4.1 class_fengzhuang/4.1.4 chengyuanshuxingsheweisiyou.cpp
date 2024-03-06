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

//权限：
    //public：公共权限，内类内外均可访问；
    //protected：保护权限，内类内外均可访问；               儿子可以访问父亲的保护内容；
    //private:私有权限，成员类内可以访问，类外不可访问。     儿子不可以访问父亲的私有内容；

//struct和class的区别：
    //struct 默认权限是 公有public
    //class  默认权限是 私有private


//成员属性设置为私有的优点：
    // 优点1：将所有成员属性设置为私有，自己可以控制读写权限；
    // 优点2：对于写权限，我们可以检测数据的有效性


#include<iostream>
using namespace std;

class Person
{
public:
    void setName(string name)
    {
        m_Name=name;
    }    

    string getName()
    {
        return m_Name;
    }

    void setAge(int age)
    {
        if(age<0||age>150)
        {
            cout<<"年龄不合法!"<<endl;
            return;
        }
        m_Age=age;
    }

    int getAge()
    {

        return m_Age;
    }

    void setLover(string lover)
    {
        lover=m_Lover;
    }

private:
    string m_Name;                //姓名  可读可写
    int m_Age;                    //年龄  只读
    string m_Lover;               //情人  只写
};



int main()
{
    Person p;
    p.setName("老6");
    cout<<"姓名:"<<p.getName()<<endl;

    //p.m_Age=18;
    p.setAge(38);
    cout<<"年龄："<<p.getAge()<<endl;

    p.setLover("老8");                  //可写，不可访问
    //cout<<"情人："<<p.setLover()<<endl;

    system("pause");
    return 0;
}