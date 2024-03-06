// 结构体基本概念:
// 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型。

//定义：   struct 结构体名 {结构体成员列表}；

//通过结构体创建变量的方式有如下三种：
    //struct 结构体名 变量名
    //struct 结构体名 变量名={成员1值，成员2值......}
    //定义结构体时顺便创建变量


//作用：通过指针访问结构体中的成员
//语法：利用操作符 ->可以通过结构体指针访问结构体属性

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
    struct student stu={"李1",19,90};
    

    struct student *p=&stu;

    p->score=80;                            //指正通过->操作符访问成员

    cout<<"姓名:"<<p->name<<" 年龄："<<p->age<<" 分数："<<p->score<<endl;  


    system("pause");
    return 0;
}


// 总结：结构体指针可以通过 -> 操作符 来访问结构体中的成员`