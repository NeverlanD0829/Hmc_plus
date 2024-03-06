/*
例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中心内容不同
接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承存在的意义以及好处

	继承的基本语法： class 子类：继承方式 父类
	继承一共有三种方式：公共继承（public），保护继承(protected)，私有继承(private)
*/


#include<iostream>
#include<string>
using namespace std;

class Base1
{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;
};

class Son1:public Base1
{
	public:
	void func()
	{
		m_a=100;	//可访问
		m_b=50;		//保护权限，可访问
		// m_c=25;
	}
};

void myclass01()
{
	Son1 s1;
	s1.m_a;
	// s1.m_b;	    //不可访问
}

class Son2:protected Base1
{
	public:
	void func()
	{
		m_a=100;	//可访问
		m_b=50;		//保护权限，可访问
		// m_c=25;
	}
};

void myclass02()
{
	Son2 s1;
	// s1.m_a;				//不可访问
}

class Son3:private Base1
{
	public:
	void func()
	{
		m_a=100;	//不可访问
		m_b=50;		//不可访问
		// m_c=25;
	}
};

class GrandSon3 :public Son3
{
public:
	void func()
	{
		//Son3是私有继承，所以继承Son3的属性在GrandSon3中都无法访问到
		//m_A;
		//m_B;
		//m_C;
	}
};

int main() 
{
	// myclass02();

	system("pause");

	return 0;
}

