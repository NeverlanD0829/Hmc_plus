//二维数组定义的四种方式：
    // 数据类型 数组名[ 行数 ][ 列数 ];
    // 数据类型 数组名[ 行数 ][ 列数 ] = { {数据1，数据2 } ，{数据3，数据4 } };              这种定义方式用的最多。
    // 数据类型 数组名[ 行数 ][ 列数 ] = { 数据1，数据2，数据3，数据4};
    // 数据类型 数组名[ ][ 列数 ] = { 数据1，数据2，数据3，数据4};

//案例描述：有三名同学（张三，李四，王五），在一次考试中的成绩分别如下表，请分别输出三名同学的总成绩
    //      语文	数学	英语
    // 张三	100	    100	    100
    // 李四	90	    50	    100
    // 王五	60	    70	    80


#include<iostream>
#include<string>
using namespace std;


int main()
{
    //二维数组写入成绩信息
    int arr[3][3]=
    {{100,100,100},
     {90,150,100},
     {60,70,80}};

    //一维数组写入姓名
    string name[3]={"张三","李四","王五"};

    for(int i=0;i<3;i++)
    {
        int score=0;
        for(int j=0;j<3;j++)
        {
            
            score+=arr[i][j];
        }
        cout<<name[i]<<"同学的总成绩为："<<score<<endl;
    }
    system("pause");
    return 0;
}