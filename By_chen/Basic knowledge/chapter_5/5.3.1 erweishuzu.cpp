//二维数组定义的四种方式：
    // 数据类型 数组名[ 行数 ][ 列数 ];
    // 数据类型 数组名[ 行数 ][ 列数 ] = { {数据1，数据2 } ，{数据3，数据4 } };              这种定义方式用的最多。
    // 数据类型 数组名[ 行数 ][ 列数 ] = { 数据1，数据2，数据3，数据4};
    // 数据类型 数组名[ ][ 列数 ] = { 数据1，数据2，数据3，数据4};


#include<iostream>
#include<string>
using namespace std;


int main()
{
    //第一种定义方式
    cout<<"第一种输出方式输出的数组："<<endl;
    int a[2][3];
    a[0][0]=1;
    a[0][1]=2;
    a[0][2]=3;
    a[1][0]=4;
    a[1][1]=5;
    a[1][2]=6;

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    //第二种定义方式
    cout<<"第二种输出方式输出的数组："<<endl;
    int b[2][3]={{4,5,6},{7,8,9}};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    //第三种定义方式
    cout<<"第三种输出方式输出的数组："<<endl;
	int c[2][3] = { 1,2,3,4,5,6 }; 
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }

    //第四种定义方式
    cout<<"第四种输出方式输出的数组："<<endl;
	int d[][2] = { 1,2,3,4,5,6 }; 
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}