#include <iostream>
#include <string>
#include<windows.h>
using namespace std;

int main()
{
    //作用：从键盘获取数据
    //关键字：cin
    //语法：cin>>变量
    SetConsoleOutputCP ( CP_UTF8 ) ;            //在#include<windows.h>头文件中用“ SetConsoleOutputCP ( CP_UTF-8 ) ; ”函数，把控制台输出代码页修改成UTF-8编码格式
    //整型
    int a=0;
    cout<<"请输入整型变量:"<<endl;
    cin>>a;
    cout<<"输入的整形变量是："<<a<<endl;
/*
     //浮点型
    double d=0;
    cout<<"请输入浮点型变量:"<<endl;
    cin>>d;
    cout<<"输入的浮点型变量是："<<d<<endl;

    //字符串
    string mima;
    cout<<"请输入字符串型变量："<<endl;
    cin>>mima;
    cout<<mima<<endl;

    //布尔类型     只要非0，都代表真。
    bool flag=true;
    cout<<"请输入布尔类型变量："<<endl;
    cin>>flag;
    cout<<flag<<endl;
*/
   

    system("pause");
    return 0;
}