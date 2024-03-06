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
//EG1:
#include<iostream>
using namespace std;
const double PI=3.14;

class circle
{
    public:
    int r;
    double zc()
    {
        return 2*PI*r;
    }
};



int main()
{
    circle c1;              //  类的实例化
    c1.r=10;
    cout<<"圆的周长为："<<c1.zc()<<endl;



    system("pause");
    return 0;
}