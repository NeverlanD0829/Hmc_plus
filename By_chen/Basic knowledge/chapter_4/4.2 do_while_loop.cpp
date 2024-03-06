#include <iostream>
#include <string>
#include <ctime>
using namespace std;    //time函数可以获取当前的系统时间（但是获取的是秒数，是从1970年1月1日零时零分零秒到目前为止所经过的时间），time可以将其转化为常规的时间



//语法 ：   do{ 循环语句 } while(循环条件);
//与while的区别在于do…while会先执行一次循环语句，再判断循环条件


//while循环练习案例：猜数字
//案例描述：系统随机生成一个1到100之间的数字，玩家进行猜测，如果猜错，提示玩家数字过大或过小，如果猜对恭喜玩家胜利，并且退出游戏。



int main() 
{

    int num=0;
    do
    {
        cout<<"num="<<num<<endl;
        num++;
    }
    while(num<10);
   

	system("pause");
	return 0;
}