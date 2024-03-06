//C/C++支持最基本的三种程序运行结构：顺序结构、选择结构、循环结构
//顺序结构：程序按顺序执行，不发生跳转
//选择结构：依据条件是否满足，有选择的执行相应功能
//循环结构：依据条件是否满足，循环多次执行某段代码

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


//逻辑运算符  --- 或
int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    int weight1=0;
    cout<<"请输入猪猪的体重:"<<endl;
    cin>>weight1;

    int weight2=0;
    cout<<"请输入猪猪的体重:"<<endl;
    cin>>weight2;

    int weight3=0;
    cout<<"请输入猪猪的体重:"<<endl;
    cin>>weight3;

    if(weight1<=weight2)
    {
        weight1=weight2;
    }
    else
    {
        weight1=weight1;
    }
    
    if(weight3<=weight1)
    {
        weight1=weight1;
        cout<<"最重的小猪是："<<weight1<<endl;
    }
    else
    {
        cout<<"最重的小猪的体重（kg）是："<<weight3<<endl;
    }

	system("pause");
	return 0;
}
 