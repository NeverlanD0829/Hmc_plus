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
    for(int i=1;i<10;i++)
    {
        if(i==5)
        {
            break;
        }
        cout<<i<<endl;
    }

	system("pause");
	return 0;
}
  