// 结构体基本概念:
// 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型。

//定义：   struct 结构体名 {结构体成员列表}；

//通过结构体创建变量的方式有如下三种：
    //struct 结构体名 变量名
    //struct 结构体名 变量名={成员1值，成员2值......}
    //定义结构体时顺便创建变量

#include<string>
#include<iostream>
using namespace std;


struct student              //结构体定义
{
    //成员列表
    string name;    
    int age;
    int score;
}stu3;                      //结构体变量创建方式3




int main()
{
    //创建结构体变量方式1:
    struct student stu1;
    stu1.name="张三";
    stu1.age=18;
    stu1.score=100;

    cout<<"姓名:"<<stu1.name<<" 年龄："<<stu1.age<<" 分数："<<stu1.score<<endl;

    //结构体变量创建方式2

    struct student stu2={"李四",19,60};
    cout<<"姓名:"<<stu2.name<<" 年龄："<<stu2.age<<" 分数："<<stu2.score<<endl;  


    //结构体变量创建方式3(定义结构体时顺便创建变量)
    stu3.name="王五";
    stu3.age=18;
    stu3.score=80;
    cout<<"姓名:"<<stu3.name<<" 年龄："<<stu3.age<<" 分数："<<stu3.score<<endl;  
    

    system("pause");
    return 0;
}


// 总结1：定义结构体时的关键字是struct，不可省略

// 总结2：创建结构体变量时，关键字struct可以省略

// 总结3：结构体变量利用操作符 ‘’.’’ 访问成员