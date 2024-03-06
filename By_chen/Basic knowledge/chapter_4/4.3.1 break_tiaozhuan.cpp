#include <iostream>
#include <string>
using namespace std;


//break语句作用: 用于跳出选择结构或者循环结构

//break使用的时机：
//出现在switch条件语句中，作用是终止case并跳出switch
//出现在循环语句中，作用是跳出当前的循环语句
//出现在嵌套循环中，跳出最近的内层循环语句

int main() 
{
    cout<<"请输入您老人家挑战副本的难度："<<endl;
    cout<<"普通难度:1"<<endl;
    cout<<"一般难度:2"<<endl;
    cout<<"地狱级难度:3"<<endl;

    int num;
    cin>>num;

    switch (num)
    {
    case 1:
        cout << "您选择的是普通难度" << endl;
        break;
    case 2:
        cout << "您选择的是一般难度" << endl;
        break;
    default:
        cout << "傻逼，你选择的是地狱级难度" << endl;
        break;
    }


	system("pause");
	return 0;
}
  