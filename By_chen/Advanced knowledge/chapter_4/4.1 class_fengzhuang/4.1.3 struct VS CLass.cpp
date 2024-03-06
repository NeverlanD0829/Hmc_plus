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
    //class  默认权限是 私有private,不可访问


#include<iostream>
using namespace std;
const double PI=3.14;

class C1
{
    int m_A;
};

struct C2
{
   
    int m_B;
};



int main()
{
    C1 C1;
    //C1.m_A=100;               //错误，访问权限是私有，不可访问



    C2  c2;
    c2.m_B=1000;               //正确，访问权限是公有
    system("pause");
    return 0;
}