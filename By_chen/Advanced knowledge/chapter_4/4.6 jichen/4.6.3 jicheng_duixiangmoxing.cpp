/*
例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中心内容不同
接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承存在的意义以及好处

	继承的基本语法： class 子类：继承方式 父类
	继承一共有三种方式：公共继承（public），保护继承(protected)，私有继承(private)

	问题：从父类继承过来的成员，啊哪些属于子类对象中？
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
	int m_c;					//私有成员只是被隐藏了，但还会继续继承下去
};



class Son:public Base1
{
	public:
	int m_d;
};

void test01()
{
	cout<<"szieof Son="<<sizeof(Son)<<endl;					//结果为16   四个int型为16字节
}

int main() 
{
	test01();

	system("pause");

	return 0;
}


//父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到