// 结构体基本概念:
// 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型。

//定义：   struct 结构体名 {结构体成员列表}；

//通过结构体创建变量的方式有如下三种：
    //struct 结构体名 变量名
    //struct 结构体名 变量名={成员1值，成员2值......}
    //定义结构体时顺便创建变量


//结构体中 const使用场景作用：用const来防止误操作



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

void zhichuandi(student stu)
{
    stu.age=28;
    cout<<"子函数中 姓名:"<<stu.name<<" 年龄:"<<stu.age<<" 分数:"<<stu.score<<endl;
}

void dizhichuandi(student *stu)
{
    stu->age=28;
    cout<<"子函数中 姓名:"<<stu->name<<" 年龄:"<<stu->age<<" 分数:"<<stu->score<<endl;
}



int main()
{
    student stu={"张三",18,100};

    //值传递

    zhichuandi(stu);
    cout<<"姓名:"<<stu.name<<" 年龄："<<stu.age<<" 分数："<<stu.score<<endl;   
    cout<<endl;


    //地址传递

    dizhichuandi(&stu);
    cout<<"姓名:"<<stu.name<<" 年龄："<<stu.age<<" 分数："<<stu.score<<endl;   

    system("pause");
    return 0;
}


// 总结：如果不想修改主函数中的数据，用值传递，反之用地址传递