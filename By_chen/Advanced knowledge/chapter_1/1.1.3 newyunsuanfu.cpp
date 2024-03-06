// 栈区：
	// 由编译器自动分配释放，存放函数的参数值，局部变量等。
	// 注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
// 堆区：
	// 有程序员分配释放，若程序员不释放，程序结束之后有操作系统回收
	// 在C++中主要利用new在堆区中开辟内存
	// int* p = new int(10);
	// 1
// new运算符
// 在堆区开辟数据

// 堆区开辟的数据，由程序员手动开辟，手动释放，释放用delete


#include<iostream>
#include<string>
using namespace std;

//栈区数据的注意事项：不要返回局部变量的地址！（栈区的数据由编译器管理开辟和释放）
int* func()					//形参数据也会存放在栈区
{
	int *a=new int(10);		    //局部变量存放在栈区，栈区内存数据在函数执行完后自动释放。
	return a;					//返回局部变量的地址
}
int main()
{
	//接受func函数的返回值
	int*p=func();
	
	cout<<*p<<endl;
	cout<<*p<<endl;

	delete p;					//手动释放

	cout<<*p<<endl;				//报错，释放的空间不可访问

    system("pause");
	return 0;

}
