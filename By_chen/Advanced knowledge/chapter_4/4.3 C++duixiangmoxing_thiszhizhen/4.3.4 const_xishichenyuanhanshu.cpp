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

//const修饰成员函数：
    //常函数：
        //成员函数后加const后，我们称这个函数为常函数。
        //常函数内不可以修改成员属性。
        //成员属性申明时加关键字  mutable 后，在常函数中依然可以修改其值。

    //常对象：
        //申明对象前加const称该对象为常对象
        //常对象只能调用常函数。



#include<iostream>
#include<string>
using namespace std;




class Person
{
public:

    // this指针的本质是 指针常量，指针的指向是不可以修改的。
    //const Person *const this;
    //在成员函数后面加上const，修饰的是this指向，让指针指向的值也不可以修改。

    void showPerson() const             //成员函数后加const，称该函数为  常函数，常函数内不可修改成员属性
    {
        // this->m_A=100;                //相当于m_A=100;  前有一个this指针。    this->m_A=100;
        // this=NULL;
        this->m_B=10;
        cout<<"this->m_B="<<this->m_B<<endl;
    }


    void func()
    {
        m_A=100;
    }


    int m_A=0;                      //m_Age或this指针。
    mutable int m_B=0;             //特殊变量，即使在常函数中，也可以修改这个值。
};


// void test01()
// {
//     Person p;
//     p.showPerson();

// }


void test02()
{
    const Person p0;                //在对象前加const   变为常对象。
    //p.m_A=100;
    p0.m_B=100;
    cout<<"p0.m_B="<<p0.m_B<<endl;

    //常对象只能调用常函数。
    
    p0.showPerson();                   //常对象只能调用常函数，showPerson是常函数，可调用
    // p0.func();                      //不是常函数，不可调用
}

//总结：常对象可以修改静态变量的值，只可以调用常函数。

int main()
{
    // test01();
    test02();

    system("pause");
    return 0;
}