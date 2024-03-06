// 堆区：
	// 由程序员分配释放，若程序员不释放，程序结束之后有操作系统回收
	// 在C++中主要利用new在堆区中开辟内存
	// int* p = new int(10);
	// 1

// new运算符
// 在堆区开辟数据
// 堆区开辟的数据，由程序员手动开辟，手动释放，释放用delete
//​ 利用new创建的数据，会返回该数据对应的类型的指针


#include<iostream>
#include<string>
using namespace std;

//栈区数据的注意事项：不要返回局部变量的地址！（栈区的数据由编译器管理开辟和释放）

int *func()					//形参数据也会存放在栈区
{
	int *p=new int(10);			//new返回该数据类型的指针
	return p;					//返回局部变量的地址
}

void test01()
{
    int *p=func();
    cout<<*p<<endl;
    cout<<*p<<endl;
    cout<<*p<<endl;              //堆区的数据由程序员管理释放
    delete p;                  //如果想释放堆区的数据，就利用关键字 delete
    cout<<*p<<endl;            //报错，释放的空间不可访问
}
 
//在堆区利用new开辟数组
void test02()
{
    int * arr=new int[10];            //10代表数组有10个元素
    for (int i=0;i<10;i++)
    {
        arr[i]=i+100;
    }

    for (int i=0;i<10;i++)
    {
        cout<<arr[i]<<endl;
    }

    //释放堆区数组
    //释放堆区数组时，要加[]才可以。

    //以下操作输出时乱码。
    delete[] arr;
    for (int i=0;i<10;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
	//接受func函数的返回值
	test01();
    test02();


    system("pause");
	return 0;

}
