#include <iostream>
#include <string>
#include <ctime>
using namespace std;    //time函数可以获取当前的系统时间（但是获取的是秒数，是从1970年1月1日零时零分零秒到目前为止所经过的时间），time可以将其转化为常规的时间



//语法 ：   while(循环条件){循环语句}
//循环条件为真，则执行循环语句,在执行循环语句时候，程序必须提供跳出循环的出口，否则出现死循环


//while循环练习案例：猜数字
//案例描述：系统随机生成一个1到100之间的数字，玩家进行猜测，如果猜错，提示玩家数字过大或过小，如果猜对恭喜玩家胜利，并且退出游戏。



int main() 
{
    srand((unsigned int)time(NULL));      //srand是随机数发生器的初始化函数，这个函数位于头文件里面。
    int num=rand()%100+1;                //rand()%100生成0~99的随机数。rand（）%100+1生成0+1~99+1~的随机数


    //玩家进行猜测

    int val;
    while (1)
    {
        cout<<"小伙，来把你猜的数告诉我："<<endl;
        cin>>val;
        
        if(val>num)
        {
            cout<<"猜的太大了"<<endl;
        }
        else if(val<num)
        {
            cout<<"猜的太小了"<<endl;
        }
        else
        {
             cout<<"恭喜你，让你蒙对了！"<<endl;
             break;
        }
    }
    

	system("pause");
	return 0;
}
 