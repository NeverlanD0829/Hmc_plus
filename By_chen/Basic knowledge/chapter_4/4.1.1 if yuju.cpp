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
    //输入一个分数，如果大于600，则视为考上一本大学；
    SetConsoleOutputCP(CP_UTF8);
    //SetConsoleOutputCP(CP_UTF8);        //控制台输出代码页修改成UTF-8编码格式。
    int score=0;
    cout<<"请输入你的高考分数:"<<endl;
    cin>>score;

    if(score>=600)
    {
        cout<<"小伙子，你考上985啦"<<endl;
    }
    else if(score>=540 && score<600)
    {
        cout<<"还可以，有个211可以读！"<<endl;
    }
    else if(score>=480 && score<540)
    {
        cout<<"还可以，有个一本可以读！"<<endl;
    }
      else if(score>=400 && score<480)
    {
        cout<<"还可以，有个本科可以读！"<<endl;
    }
     else 
    {
        cout<<"再来一年吧！少年！"<<endl;
    }
	system("pause");
	return 0;
}
 