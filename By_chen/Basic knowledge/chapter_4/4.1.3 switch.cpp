//C/C++支持最基本的三种程序运行结构：顺序结构、选择结构、循环结构
//顺序结构：程序按顺序执行，不发生跳转
//选择结构：依据条件是否满足，有选择的执行相应功能
//循环结构：依据条件是否满足，循环多次执行某段代码

#include <iostream>
#include <string>
using namespace std;


//switch语句：执行多条件分支语句
//与if语句比，对于多条件判断时，switch的结构清晰，执行效率高，缺点是switch不可以判断区间。


int main() 
{
    //

    int score=0;
    cout<<"请给《八角笼中》值这部电打分(满分10分)："<<endl;
    cin>>score;

    switch (score)
    {
    case 10:
    case 9:
        cout<<"是个好片，值得推荐！"<<endl;
        break;
    case 8:
    case 7:
        cout<<"还可以，挺感人！"<<endl;
        break;
    
    case 6:
    case 5:
        cout<<"凑合！"<<endl;
        break;

    default:
        cout<<"宝强加油，这可不行！"<<endl;
        break;
    }



	system("pause");
	return 0;
}
 