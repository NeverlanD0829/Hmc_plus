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


#include<iostream>
using namespace std;
const double PI=3.14;

class person
{
    public:
        string name;

    protected:
        string car;
    
    private:
        int   passward;

  
    public:
        void show()
        {
            name="chengcheng";
            car="benz";
            passward=1234;
            cout<<"姓名:"<<name<<"  汽车："<<car<<"  密码："<<passward<<endl;
        }
};



int main()
{
    person p1;
    p1.name="肉丝";
    //p1.car="baoma";                   //保护权限和私有权限，类外访问不到。
    //p1.passward=234789;
    
    p1.show();
    system("pause");
    return 0;
}