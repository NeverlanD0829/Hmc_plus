//运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型
//加号（+）运算符重载，实现两个自定义数据类型的相加运算

//左移运算符重载：可以输出自定义数据类型

//递增运算符作用：通过重载递增运算符，实现自己的整形数据

#include<iostream>                             //iostream：input/output stream  输入输出流库     cout是标准输出流对象
#include<string>
using namespace std;

class MyInteger {

	friend ostream& operator<<(ostream& out, MyInteger myint);

public:
	MyInteger() {
		m_Num = 0;
	}
	//前置++运算符重载，返回引用是为了对一个数进行递增
	MyInteger& operator++() {                               //前置递增返回引用
		//先++
		m_Num++;
		//再返回
		return *this;
	}

	//后置++运算符重载
	MyInteger operator++(int) {                             //int代表占位参数，可用于区分前置递增还是后置递增。后置递增返回值
		//先返回
		MyInteger temp = *this;                             //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
		m_Num++;
		return temp;
	}

private:
	int m_Num;
};


ostream& operator<<(ostream& out, MyInteger myint) {
	out << myint.m_Num;
	return out;
}


//前置++ 先++ 再返回
void test01() {
	MyInteger myInt;
	cout << ++myInt << endl;
	cout << myInt << endl;
}

//后置++ 先返回 再++
void test02() {

	MyInteger myInt;
	cout << myInt++ << endl;
	cout << myInt << endl;
}

int main() {

	test01();
	test02();

	system("pause");

	return 0;
}



//总结：重载运算符配合友元可以实现输出自定义数据类型。