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

	继承同名函数成员处理方式
		问题：子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据的？
		结论：访问子类同名成员，直接访问即可；   访问父类同名成员，需要加作用域

	继承同名静态成员处理方式
		问题：继承中同名的静态成员在子类对象上如何进行访问？
		结论：静态成员与非静态成员出现同名，处理方式一致：
			//访问子类同名成员，直接访问即可
			//访问父类同名成员，需要加作用域
*/


#include<iostream>
#include<string>
using namespace std;

class Base
{
public:
	static void func()
	{
		cout<<"Base-static void func()"<<endl;
	}
	static void func(int a)
	{
		cout<<"Base-static void func(int a)"<<endl;
	}
	static int m_A;
};
int Base::m_A = 100;

class Son:public Base
{
	public:
	static void func()
	{
		cout<<"Son-static void func()"<<endl;
	}
	static void func(int a)
	{
		cout<<"Son-static void func(int a)"<<endl;
	}
	static int m_A;
};

int Son::m_A = 200;

//同名成员属性


void test01()												//通过对象访问
{

	cout<<"通过对象访问："<<endl;
	Son s;
	cout << "Son下的m_A = " << s.m_A << endl;
	cout << "Base下的m_A = " << s.Base::m_A << endl;			//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数,如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域

	s.func();
	s.Base::func();
	s.Base::func(3);
}

void test02()													//通过类名访问
{

	cout<<"通过类名访问："<<endl;
	Son s;
	cout << "Son下的m_A = " << Son::m_A<< endl;
	cout << "Base下的m_A = " << Son::Base::m_A << endl;			//当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数,如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域

	s.func();
	Son::func();
	Son::func(3);
}

int main() 
{
	test01();
	test02();
	system("pause");

	return 0;
}


/*
总结：	
	同名静态成员处理方式和非静态处理方式一样，只不过有两种访问的方式（1.通过对象    2.通过类名）
*/