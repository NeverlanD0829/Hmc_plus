// 结构体基本概念:
// 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型。

//定义：   struct 结构体名 {结构体成员列表}；

//通过结构体创建变量的方式有如下三种：
    //struct 结构体名 变量名
    //struct 结构体名 变量名={成员1值，成员2值......}
    //定义结构体时顺便创建变量


//作用：结构体中的成员可以是另一个结构体
//例如：每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体



#include<string>
#include<iostream>
using namespace std;


struct student                       //结构体定义
{
    //成员列表
    string name;    
    int age;
    int score;
}; 

struct teacher
{
    int id;
    string name;
    int age;
    struct student stu;              //子结构体
};



int main()
{
    struct teacher t1;
    t1.id=2200343;
    t1.name="NeverlanD";
    t1.age=40;

    t1.stu.name="李鸽er";
    t1.stu.age=80;
    t1.stu.score=100;


    cout<<"姓名:"<<t1.name<<" 年龄："<<t1.age<<" 学号："<<t1.id<<endl; 
    cout<<"姓名:"<<t1.stu.name<<" 年龄："<<t1.stu.age<<" 分数："<<t1.stu.score<<endl;   


    system("pause");
    return 0;
}


// 总结：结构体指针可以通过 -> 操作符 来访问结构体中的成员`