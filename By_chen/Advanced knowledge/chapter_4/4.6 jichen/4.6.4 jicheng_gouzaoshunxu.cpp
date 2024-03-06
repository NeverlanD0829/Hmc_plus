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
*/


#include<iostream>
#include<string>
using namespace std;

class Base
{
public:
	Base()
	{
		cout<<"Base构造函数！"<<endl;
	}

	~Base()
	{
		cout<<"Base析构函数！"<<endl;
	}
};



class Son:public Base
{
	public:
	Son()
	{
		cout<<"Son构造函数！"<<endl;
	}

	~Son()
	{
		cout<<"Son析构函数！"<<endl;
	}
};

void test01()
{
	
	Son s;
}

int main() 
{
	test01();

	system("pause");

	return 0;
}


//父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到