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

#include<iostream>                             //iostream：input/output stream  输入输出流库     cout是标准输出流对象
#include<string>
using namespace std;

class Person
{
public:
    Person(string name,int age)
    {
        this->m_Name=name;
        this->m_Age=age;
    }

    bool operator==(Person &p)                //重载==运算符
    {
        if(this->m_Name==p.m_Name && this->m_Age==p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(Person &p)                //重载==运算符
    {
        if(this->m_Name==p.m_Name && this->m_Age==p.m_Age)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    string m_Name;
    int m_Age;
    
};

void test01()                               //正常函数可实现数值关系对比。
{
    int a=0;
    int b=8;
    if (a == b)
	{
		cout << "a和b相等" << endl;
	}
	else
	{
		cout << "a和b不相等" << endl;
	}

	if (a != b)
	{
		cout << "a和b不相等" << endl;
	}
	else
	{
		cout << "a和b相等" << endl;
	}
}


void test02()
{
    Person p1("PS",20);
    Person p2("PS",38);

    if (p1 == p2)
	{
		cout << "p1和p2相等" << endl;
	}
	else
	{
		cout << "p1和p2不相等" << endl;
	}

	if (p1 != p2)
	{
		cout << "p1和p2不相等" << endl;
	}
	else
	{
		cout << "p1和p2相等" << endl;
	}


}


int main() {

	// test01();
    test02();


	system("pause");

	return 0;
}



//总结：重载运算符配合友元可以实现输出自定义数据类型。