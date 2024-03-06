/*
例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中心内容不同
接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承存在的意义以及好处

	继承的基本语法： class 子类：继承方式 父类
	继承一共有三种方式：公共继承（public），保护继承(protected)，私有继承(private)

	问题：从父类继承过来的成员，啊哪些属于子类对象中？

	继承中的构造和析构顺序：
		子类继承父类后，创建子类对象也会调用父类构造函数
		问题：父类和子类的构造、析构顺序谁先？谁后？
		结论：继承中，先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反

	继承同名函数成员处理方式：
		问题：子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据的？
		结论：访问子类同名成员，直接访问即可；   访问父类同名成员，需要加作用域

	继承同名静态成员处理方式：
		问题：继承中同名的静态成员在子类对象上如何进行访问？
		结论：静态成员与非静态成员出现同名，处理方式一致：
			//访问子类同名成员，直接访问即可
			//访问父类同名成员，需要加作用域

	多继承语法：
		c++允许一个类继承多个类
		语法：    class 子类：继承方式 父类1，继承方式 父类2
		多继承会引发父类中有同名成员的出现，需要加作用域区分
		*实际开发中不建议用多类继承
*/


#include<iostream>
#include<string>
using namespace std;

class Base1
{
public:
	Base1()
	{
		m_A=100;
	}
public:
	int m_A;
};

class Base2
{
public:
	Base2()
	{
		m_A=200;
	}
public:
	int m_A;
};

class Son:public Base1,public Base2
{

public:
	Son()
	{
		m_C=300;
		m_D=400;
	}
public:
	int m_C;
	int m_D;

};


void test01()												//通过对象访问
{
	Son s;
	cout<<"size of Son="<<sizeof(s)<<endl;
	cout<<s.Base1::m_A<<endl;
	cout<<s.Base2::m_A<<endl;

}


int main() 
{
	test01();
	system("pause");

	return 0;
}


/*
总结：	
	多继承中如果多个父类中出现了同名的情况，子类在使用时要加上作用域
*/