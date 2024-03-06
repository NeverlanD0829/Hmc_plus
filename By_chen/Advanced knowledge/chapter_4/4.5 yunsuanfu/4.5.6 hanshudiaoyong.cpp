//运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
//加号（+）运算符重载，实现两个自定义数据类型的相加运算

//左移运算符重载：可以输出自定义数据类型

//递增运算符作用：通过重载递增运算符，实现自己的整形数据

//赋值运算符重载：
    //C++编译器至少给一个类添加4个函数
        //1.默认构造函数（无参，函数体为空）
        //2.默认析构函数（无参，函数体为空）
        //3.默认拷贝构造函数，对属性进行值拷贝
        //4.赋值运算符operator=，对属性进行值拷贝
        //前三个已经学过

    //如果类中有属性指向堆区，赋值操作时也会出现深浅拷贝的问题

//关系运算符重载（==  ！=）
    //作用：重载关系运算符，让两个自定义类型对象进行对比操作（相等还是不相等）

//函数调用运算符  ()
    //重载后使用的方式像函数的调用，因此称为仿函数
    //仿函数没有固定写法，非常灵活。

#include<iostream>                             //iostream：input/output stream  输入输出流库     cout是标准输出流对象
#include<string>
using namespace std;

class Myprint
{
    public:
    void operator()(string text)
    {
        cout<<text<<endl;
    }
};

void test01()
{
    Myprint myfunc;
    myfunc("你好！李焕英。");
}

class Myadd
{
public:
    int operator()(int v1,int v2)
    {
        return v1+v2;
    }
};

void test02()
{
    Myadd add;
    int ret=add(10,10);
    cout<<"ret="<<ret<<endl;

    //匿名函数的调用           
    cout<<"MyAdd()(10,100)="<<Myadd()(10,100)<<endl;

}
int main() {

	test01();
    test02();



	system("pause");

	return 0;
}



//总结：函数的调用形式不固定，按用户需求来，上述例子中，test01中类型为string，test02中类型为int，实现的功能也不相同。
    //类名＋（）  多为匿名函数。  如Myadd()