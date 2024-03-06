// 结构体基本概念:
// 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型。

//定义：   struct 结构体名 {结构体成员列表}；

//通过结构体创建变量的方式有如下三种：
    //struct 结构体名 变量名
    //struct 结构体名 变量名={成员1值，成员2值......}
    //定义结构体时顺便创建变量


//作用：将结构体作为参数向函数中传递
//传递方式有两种：值传递  地址传递



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



void printstudent(const student *stu)
{
    //stu->age=28;                                      //操作失败，因为加了const修饰
    cout<<"子函数中 姓名:"<<stu->name<<" 年龄:"<<stu->age<<" 分数:"<<stu->score<<endl;
}



int main()
{
    student stu={"张三",18,100};

    //地址传递

    printstudent(&stu);
    cout<<"main中的姓名:"<<stu.name<<" 年龄："<<stu.age<<" 分数："<<stu.score<<endl;   

    system("pause");
    return 0;
}


// 总结：如果不想修改主函数中的数据，用值传递，反之用地址传递.   值传递占用空间大，指针传递只占4个字节，所占内存空间小。