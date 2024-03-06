////C++面向对象三大特性：封装、继承、多态
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

//案例1：设计立方体类
        //求出立方体的体积和表面积；
        //分别用全局函数（main函数外的全局函数）和成员函数（在类内的函数）判断两个立方体是否相等。


#include<iostream>
using namespace std;

class cube
{
private:            //属性
    int l;
    int w;
    int h;

public:            //行为
    void setL(double a)                     //set长度
    {
        l=a;
    }

    double getl()                           //获取长度
    {
       return l;
    }

    void setW(double b)                     //set宽度
    {
        w=b;
    }

    double getW()                           //获取宽度
    {
       return w;
    }

    void setH(double c)                     //set高度
    {
        h=c;
    }

    double getH()                           //获取高度
    {
       return h;
    }

    double s()
    {
        return 2 * ((l * w) + (l * h) + (w * h));
    }

    double v()
    {
        return l*w*h;
    }
    
    bool issameclass(cube& c)                   //该函数接受一个对 cube 类型对象的引用，并返回一个布尔值 (bool),(cube& c): 这是函数的参数列表。在这个情况下，函数期望接受一个 cube 类型的引用作为参数。引用 (&) 表示传递的是对象的引用，而不是对象的副本，这样函数可以修改传入的对象。
    {
        if ((c.getl()==l||c.getl()==w||c.getl()==h)&& (c.getW()==w ||c.getW()==l||c.getW()==h)&& (c.getH()==h||c.getH()==w||c.getH()==l))
            return true;
        else
            return false;
    }
};


//全局函数判断

bool issame(cube& c1,cube& c2)
{
    if ((c1.getl()==c2.getl()||c1.getl()==c2.getW()||c1.getl()==c2.getH() )&& (c1.getW()==c2.getW() ||c1.getW()==c2.getl()||c1.getW()==c2.getH() )&& (c1.getH()==c2.getH()||c1.getH()==c2.getW()||c1.getH()==c2.getl()))
        return true;
    else
        return false;
}



int main()
{
    cube c1,c2;             //实例化对象
    c1.setL(10);
    c1.setW(9);
    c1.setH(8);

    c2.setL(8);
    c2.setW(9);
    c2.setH(10);

    c1.s();
    cout<<"圆1的面积是："<<c1.s()<<endl;
    c1.v();
    cout<<"圆1的体积是："<<c1.v()<<endl;

    cout<<endl;

    cout<<"圆2的面积是："<<c2.s()<<endl;
    cout<<"圆2的体积是："<<c2.v()<<endl;

    bool ret1=c1.issameclass(c2);                       //成员函数判断两个立方体相不相等
    if(ret1)
    {
        cout<<"成员函数判断两个立方体相等"<<endl;
    }
    else
        cout<<"成员函数判断两个立方不相等"<<endl; 


    bool ret2=issame(c1,c2);                       //成员函数判断两个立方体相不相等
    if(ret2)
    {
        cout<<"全局函数判断两个立方体相等"<<endl;
    }
    else
        cout<<"全局函数判断两个立方不相等"<<endl; 

    system("pause");
    return 0;
}