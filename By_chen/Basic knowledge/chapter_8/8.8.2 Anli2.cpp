// 学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下:

// 设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员

// 学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值

// 最终打印出老师数据以及老师所带的学生数据。


#include<string>
#include<iostream>
#include<ctime>
using namespace std;


struct Student
{
	string name;
	int score;
};
struct Teacher
{
	string name;
	Student sArray[5];
};
 
void allocateSpace(Teacher tArray[] , int len)					//分配空间的函数
{
	string tName = "教师";
	string sName = "学生";
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++)
	{
		tArray[i].name = tName + nameSeed[i];
		
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].name = sName + nameSeed[j];
			tArray[i].sArray[j].score = rand() % 61 + 40;			//rand() % 61  生成0-60的随机数
		}
	}
}
 
void printTeachers(Teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << tArray[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t姓名：" << tArray[i].sArray[j].name << " 分数：" << tArray[i].sArray[j].score << endl;
		}
	}
}
 
int main() {
 
	//srand((unsigned int)time(NULL));                //随机数种子 头文件 #include <ctime>
 
	Teacher tArray[3];                              //老师数组
 
	int len = sizeof(tArray) / sizeof(Teacher);     //sizeof(tArray)=696  len=3
 
	allocateSpace(tArray, len);                     //创建数据
 
	printTeachers(tArray, len);                     //打印数据
	
    cout<<sizeof(string) <<endl;
	system("pause");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
 
	return 0;
}



// 常常使用系统时间来初始化，使用time函数来获取系统时间，得到的值是一个时间戳，即从1970年1月1日0点到现在时间的秒数，然后将得到的time_t类型数据转化为(unsigned int)的类型，然后再传给srand函数。

// 如果仍然觉得时间间隔太小，可以在(unsigned)time(0)或者(unsigned)time(NULL)后面乘上某个合适的整数。 例如,srand((unsigned)time(NULL)*10)。