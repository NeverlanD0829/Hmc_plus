//数组就是一个集合，集合里存放相同类型的数据元素
//特点：数组中每个数据元素都是相同的数据类型；          数组是由连续的内存位置组成的；      数组名的命名规范与变量名命名规范一致，不要和变量重名

//语法： 数据类型 数组名[ 数组长度 ];
//      数据类型 数组名[ 数组长度 ] = { 值1，值2 ...};
//      数据类型 数组名[ ] = { 值1，值2 ...};


#include<iostream>
#include<string>
using namespace std;


int main()
{
    //第一种数组命名方式
    cout<<"数组的第一种命名方式："<<endl;
    int score[10];

    //下标赋值
    score[0]=99;
    score[1]=100;

    cout<<score[0]<<endl;
    cout<<score[1]<<endl;

    cout<<"数组的第二种命名方式："<<endl;
    //第二种定义方式
    int score2[10]={100, 90,80,70,60,50,40,30,20,10};
    cout<<score2[4]<<endl;      //一个一个输出
    cout<<score2[4]<<endl;

    //循环输出
    for(int i=0;i<10;i++)
    {
        cout<<score2[i]<<endl;
    }

    cout<<"数组的第三种命名方式："<<endl;

    int score3[]={100,90,80,70,60,50,40,30,20,10};
    for(int i=0;i<10;i++)
    {
        cout<<score2[i]<<endl;
    }
    system("pause");
    return 0;
}