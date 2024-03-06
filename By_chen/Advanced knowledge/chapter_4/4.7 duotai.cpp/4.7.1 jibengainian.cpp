/*
    多态是C++面向对象三大特性之一。
    分类：
        静态多态：函数重载、运算符重载属于静态多态，复用函数名。
        动态多态：派生类（子类）、虚函数实现运行时多态
    区别：
        1、静态多态的函数地址 早绑定(编译阶段确定函数地址)
        2、动态多态的函数地址 晚绑定(运行阶段确定函数地址)
        函数重写的概念：函数返回值类型、函数名、参数列表完全相等。重写时virtual关键字可写可不写。


 
*/

#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout<<"动物在说话"<<endl;
    }
};

 class Cat:public Animal
 {
 public:
    void speak()
    {
        cout<<"小猫在说话"<<endl;
    }
 };

class Dog:public Animal
{
public:
    void speak()
    {
        cout<<"小狗正在说话"<<endl;
    }
};


/*  定义了一个函数 dospeak，它接受一个 Animal 类型的引用作为参数。这个函数可以用来处理任何 Animal 类型的对象（包括 Animal 的派生类对象，因为派生类对象也是 Animal 类型的）。
这种使用引用的方式允许函数在不复制对象的情况下直接操作对象，提高了效率并允许对原始对象进行修改。  
*/

void dospeak(Animal &animal)                        //我们希望传入什么对象，那么就调用什么对象的函数
{
    animal.speak();
}
 

void test01()
{
    Cat cat;
    dospeak(cat);

    Dog dog;
    dospeak(dog);
}



int main()
{
    test01();

    system("pause");
    return 0;
}


/*
总结：1.如果函数地址在编译阶段就能确定，那么静态联编;     
      2.如果函数地址在运行阶段才能确定，就是动态联编;
      3.多态满足的条件：有继承关系；子类  重写  父类中的虚函数，但关键字virtual可省略。     重写：函数返回值类型 函数名 参数列表 完全一致称为重写
      4.多态的使用：父类指针或引用指向子类对象。


*/
