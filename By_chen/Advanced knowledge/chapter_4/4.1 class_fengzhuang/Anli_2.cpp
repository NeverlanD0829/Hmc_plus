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


//案例2： 
    // 1.设计一个圆形类和一个点类
    // 2.计算点和圆的关系
        
#include<iostream>
#include<cmath>
using namespace std;

class circle
{
private:            //属性,类内可访问类外不可访问
    int x1;
    int y1;
    int r1;

public:             //行为
    void setx(double x)                     
    {
        x1=x;
    }

    double getx()
    {
        return x1;
    }

    void sety(double y)                   
    {
        y1=y;
    }

    double gety()
    {
        return y1;
    }

    void setr(double r)                     
    {
        r1=r;
    }
    double getr()
    {
        return r1;
    }
};

class dot
{
private:            //属性
    int x2;
    int y2;
    double dis;

public:             //行为
    void setx(double x)         
    {
        x2=x;
    }

    double getx()
    {
        return x2;
    }


    void sety(double y)                
    {
        y2=y;
    }

    double gety()
    {
        return y2;
    }

    void calculateDistance( circle &c)    //希望传入一个circle类的引用
    {
        double dx=x2-c.getx();
        double dy=y2-c.gety();
        dis=sqrt(dx*dx+dy*dy);
    }

    double getdis() const
    {
        return dis;
    }

};


void loc(double dis,double r)
{
    if(dis>r)
    {
        cout<<"点在圆外"<<endl;
    }
    else if(dis==r)
    {
        cout<<"点在圆上"<<endl;
    }
    else
        cout<<"点在圆内"<<endl;
}



int main()
{
    circle c;
    dot p;
    int x,y,r=0;
    cout<<"输入圆心x坐标:"<<endl;
    cin>>x;
    cout<<endl;

    cout<<"输入圆心y坐标:"<<endl;
    cin>>y;
    cout<<endl;

    cout<<"输入半径r:"<<endl;
    cin>>r;
    cout<<endl;


    c.setx(x);
    c.sety(y);
    c.setr(r);
    cout<<"圆心为："<<"("<<c.getx() <<","<< c.gety()<<")"<<"   半径为："<<c.getr()<<endl;
    cout<<endl;

    
    
    cout<<"输入点的坐标x:"<<endl;
    cin>>x;
    cout<<endl;

    cout<<"输入点的坐标y:"<<endl;
    cin>>y;
    cout<<endl;
    p.setx(x);
    p.sety(y);
    cout<<"点的坐标为："<<"("<<p.getx() <<","<< p.gety()<<")"<<endl;
    cout<<endl;

    p.calculateDistance(c);                                 //先调用计算，才可以在下一步输出
    cout<<"点到圆心的距离为："<<p.getdis()<<endl;
    cout<<endl;


    loc(p.getdis(),c.getr());

    system("pause");
    return 0;
} 