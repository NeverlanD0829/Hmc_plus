// 结构体基本概念:
// 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型。

//定义：   struct 结构体名 {结构体成员列表}；

//通过结构体创建变量的方式有如下三种：
    //struct 结构体名 变量名
    //struct 结构体名 变量名={成员1值，成员2值......}
    //定义结构体时顺便创建变量


//作用：将自定义的结构体放入到数组中方便维护
//语法：struct 结构体名 数组名[元素个数] = { {} , {} , ... {} }

#include<string>
#include<iostream>
using namespace std;


struct student              //结构体定义
{
    //成员列表
    string name;    
    int age;
    int score;
};              


int main()
{
    struct student stu[3]=
    {
        {"李1",19,80},
        {"李2",71,60},
        {"李3",15,30}
    };

    for(int i=0;i<3;i++)
    {
        cout<<"姓名:"<<stu[i].name<<" 年龄："<<stu[i].age<<" 分数："<<stu[i].score<<endl;  
    }


    system("pause");
    return 0;
}


// 总结1：定义结构体时的关键字是struct，不可省略

// 总结2：创建结构体变量时，关键字struct可以省略

// 总结3：结构体变量利用操作符 ‘’.’’ 访问成员