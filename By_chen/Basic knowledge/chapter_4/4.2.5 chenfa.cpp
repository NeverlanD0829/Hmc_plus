#include <iostream>
#include <string>
using namespace std;



//循环嵌套作用： 在循环体中再嵌套一层循环，解决一些实际问题
//利用嵌套循环，实现九九乘法表


int main() 
{
    int i,j;
    for (i=1;i<10;i++)
    {
        for(j=1;j<=i;j++)
        {
            cout<<j<<"*"<<i<<"="<<i*j<<" ";     //以空格结束
        }
        cout<<endl;             //以endl结束，换行
    }
	system("pause");
	return 0;
}
  