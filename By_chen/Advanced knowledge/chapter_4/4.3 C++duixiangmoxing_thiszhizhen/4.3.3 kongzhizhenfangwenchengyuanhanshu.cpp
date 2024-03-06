//成员变量和成员函数分类储存
    //c++中，类内的成员变量和成员函数分开存储
    //只有  非静态成员变量  才属于类的对象上。

//this 指针：
    //c++中成员变量和成员函数分开存储的，每一个非静态成员函数只会诞生一份函数实例，也就是说多个类型的对象会共用一块代码。
    //问题是： 这一块代码是如何区分那个对象调用自己的呢？
    //解决：  this指针指向 被调用的成员函数 所属的对象。
    //this指针：隐含每一个非静态成员函数的一种指针，this指针不需要定义，直接使用即可。
    //this指针作用：
        //形参和成员变量同名时，可用this指针来区分
        //类的非静态成员函数中返回对象本身，可用    return *this

//C++中，空指针也是可以调用成员函数的，但要注意有没有用到this指针。
//如果用到this指针，需加以判断保证代码的健壮性。



#include<iostream>
#include<string>
using namespace std;




class Person
{
public:
    void showClassName()
    {
        cout<<"this is Person class"<<endl;
    }

    void showPersonAge()
    {
        //报错原因：传入指针是NULL
        //加入以下代码解决该问题：

        if(this==NULL)
        {
            return;                         //如果this是空指针，直接return，不往下执行，即不访问 m_Age。保证代码健壮性。
        }

        cout<<"age="<<m_Age<<endl;          //用到m_Age属性，该属性前都默认的加了   this->m_Age,  表示当前对象的属性。这里this指向一个空值，所以访问里边的对象是不可能的。
    }

    int m_Age;            //  m_Age或this指针。
};


void test01()
{
    Person *p=NULL;
    p->showClassName();
    p->showPersonAge();

}


int main()
{
    test01();

    system("pause");
    return 0;
}