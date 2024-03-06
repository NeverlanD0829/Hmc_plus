//成员变量和成员函数分类储存
    //c++中，类内的成员变量和成员函数分开存储
    //只有  非静态成员变量  才属于类的对象上。（静态成员变量、非静态成员函数及非静态成员函数）



#include<iostream>
#include<string>
using namespace std;

class Person
{
    int m_A;

    static int m_B;             //加上静态成员变量后，其不属于类的对象上，因此test02输出还是 4 个字节。
    void func1(){}              //加上非静态成员函数后，由于成员对象和成员函数是分开储存的，因此其不属于类的对象上，因此test02输出还是 4 个字节。
    static void func2(){}       //加上静态成员函数后，由于成员对象和成员函数是分开储存的，因此其不属于类的对象上，因此test02输出还是 4 个字节。
};

//总结：  只有静态成员函数属于类的对象上。


void test01()
{
    Person p0;
    //空对象占用的内存空间为：1 ，因为c++编译器给每个空对象夜分配一个字节空间，是为了区分空对象占内存的位置，每个空对象也得有一格独一无二的内存地址。
    cout<<"size of p="<<sizeof(p0)<<endl;
}

void test02()
{
    Person p1;
    cout<<"size of p="<<sizeof(p1)<<endl;
}

int main()
{
    test01();
    //test02();

    system("pause");
    return 0;
}