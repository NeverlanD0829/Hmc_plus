// 学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下:

// 设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员

// 学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值

// 最终打印出老师数据以及老师所带的学生数据。


#include<iostream>
#include<ctime>
using namespace std;

struct  Student
{
    string name;
    int score;
};

struct  Teacher 
{
    string name;
    Student sArray[5];
};

void allocateSpace(Teacher tArray[],int len)
{
    string tname="教师";
    string sname="学生";
    string nameSeed="ABCDE";
    for(int i=0;i<len;i++)
    {
        tArray[i].name=tname+nameSeed[i];

        for(int j=0;j<5;j++)
        {
            tArray[i].sArray[j].name=sname+nameSeed[j];
            tArray[i].sArray[j].score=rand()%61+40;
        }
    }

}

void printTeachers(Teacher tArray[],int len)
{
    for (int i=0;i<len;i++)
    {
        cout<<tArray[i].name<<endl;
        for(int j=0;j<5;j++)
        {
            cout << "\t姓名：" << tArray[i].sArray[j].name << " 分数：" << tArray[i].sArray[j].score << endl;
        }
    }

}



int main()
{
    srand((unsigned int)time(NULL));

    Teacher tArray[3];
    int len=sizeof(tArray)/sizeof(Teacher);

    allocateSpace(tArray,len);
    printTeachers(tArray,len);


    system("pause");
    return 0;
}

