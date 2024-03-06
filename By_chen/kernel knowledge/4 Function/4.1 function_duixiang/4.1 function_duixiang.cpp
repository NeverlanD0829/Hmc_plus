/*
    3.函数对象
        3.3.1函数对象的概念
            重载函数调用操作符的类，其对象称为函数对象。
            函数对象使用重载的（）时，行为类似函数调用，也称仿函数。
            本质：
                函数对象（仿函数）是一个类，不是一个函数。
        3.3.2函数对象使用
            特点：
                函数对象在使用时，也可以像普通函数那样调用，可以有返回值。
                函数对象超出普通函数的概念，函数对象可以有自己的状态。
                函数对象可以作为参数传递。
*/

#include <iostream>
#include <string>
using namespace std;

class MyAdd
{
    public:
        int operator()(int v1,int v2)               // 函数对象在使用时，也可以像普通函数那样调用，可以有返回值。
        {
            return v1+v2;
        }
};

void test01()
{
    MyAdd myadd;
    cout<<myadd(16,56)<<endl;
}


class MyPrint                                       //函数对象超出普通函数概念，函数对象可以有自己的状态
{
    public:
        MyPrint()
        {
            this->count=0;
        }
        void operator()(string test)
        {
            cout<<test<<endl;
            this->count++;
        }
        int count;                                   //内部变量记录状态
};

void test02()
{
    MyPrint myprint;
    myprint("dfghjkl");
    myprint("dfghjkl");
    myprint("dfghjkl");
    myprint("dfghjkl");
    cout<<"myPrint的调用次数"<<myprint.count<<endl;
}

void doPrint(MyPrint& mp,string test)       // 函数对象可以作为参数传递,将myPrint作为参数传进来
{                                           //定义了一个名为 doPrint 的函数，它接受一个 MyPrint 类型的函数对象 mp 和一个 string 类型的参数 test。
    mp(test);                               //调用了传入的函数对象mp，并传递了字符串参数 test。这实际上是调用了函数对象的 operator()，因为函数对象本质上是一个类，并且该类实现了 operator()
}
void test03()
{
    MyPrint myPrint;
    doPrint(myPrint,"c++");
}

int main()
{
    // test01();
    // test02();
    test03();
}