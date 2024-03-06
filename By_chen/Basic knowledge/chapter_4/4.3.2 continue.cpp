#include <iostream>
#include <string>
using namespace std;


//作用：在循环语句中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环
//案例：输出100以内所有奇数/偶数。
int main() 
{
    for(int i=1;i<100;i++)
    {
        if(i%2==0)
        {
            continue;
        }
        cout<<i+1<<endl;
    }

	system("pause");
	return 0;
}
  