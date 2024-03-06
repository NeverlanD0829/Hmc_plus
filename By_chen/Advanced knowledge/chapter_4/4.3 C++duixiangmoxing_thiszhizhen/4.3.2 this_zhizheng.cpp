//成员变量和成员函数分类储存
    //c++中，类内的成员变量和成员函数分开存储
    //只有  非静态成员变量  才属于类的对象上。

//this 指针：
    //c++中成员变量和成员函数分开存储的，每一个非静态成员函数只会诞生一份函数实例，也就是说多个类型的对象会共用一块代码。
    //问题是： 这一块代码是如何区分那个对象调用自己的呢？
    //解决：  this指针指向 被调用的成员函数 所属的对象。

    //this指针：隐含每一个  非静态成员函数  的一种指针，this指针不需要定义，直接使用即可。
    //this指针作用：
        //形参和成员变量同名时，可用this指针来区分
        //类的非静态成员函数中返回对象本身，可用    return *this



#include<iostream>
#include<string>
using namespace std;




class Person
{
public:
    Person(int age)
    {
        this->age=age;                  //this指针指向 被调用的成员函数p1（）  所属的对象，  即谁调用Person(int age)这个函数，this指针就指向谁
    }
    Person& PersonAddAge(Person &p)
    {
        this->age+=p.age;
        return *this;                   //返回本体，返回值不能为void，应返回Person的引用(起别名)。  不引用就会直接使用复制构造函数，因为*this这个对象会在函数结束后销毁。
    }


    int age;                            //  m_Age或this指针。
};

//1、解决名称冲突
void test01()
{
    Person p0(18);
    cout<<"p0的年龄为:"<<p0.age<<endl;
}

//2、返回对象本身用*this

void test02()
{
    Person p1(10);
    Person p2(10);
    p2.PersonAddAge(p1).PersonAddAge(p2).PersonAddAge(p1).PersonAddAge(p2);     //链式编程思想
    cout<<"p2的年龄为:"<<p2.age<<endl;
}

int main()
{
    //test01();
    test02();

    system("pause");
    return 0;
}