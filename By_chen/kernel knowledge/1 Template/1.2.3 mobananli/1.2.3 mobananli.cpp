/*
    1.模版
    1.1模版的概念
        建立通用的模具,提高复用性
    1.2函数模版
        作用:建立通用函数,函数返回值类型和形参类型可不具体指定,用虚拟类型代表
        template<typename T>
        1.2.2函数模版注意事项
            自动类型推导,必须导出一致的数据类型T才可以使用
            模版必须要确定出T的数据类型才可以使用
        1.2.3函数模版案例
            案例描述:利用函数模版封装一个排序函数,可以对不同数据类型数组进行排序
            排序规则:从小到大,排序算法为选择排序.



*/

#include <iostream>
#include <string>
using namespace std;

template <class T>               
void MySwap(T &a,T &b)
{
    T tmp=a;
    a=b;
    b=tmp;
}

template <class T>    
void MySort(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        int max=i;                  //最大值下标
        for (int j=i+1;j<len;j++)
        {
            if (arr[max]<arr[j])
            {
                max=j;
            }
        }
        if (max!=i)
        {
            MySwap(arr[i],arr[max]);
        }
    }
}
template <class T>
void PrintArray(T arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i];
    }
}
void test01()
{
    char CharArray[]="xcvbnmdfg";
    int num=sizeof(CharArray)/sizeof(char);
    MySort(CharArray,num);
    PrintArray(CharArray,num);
}



void test02()
{
    int IntArr[]={2,3,4,5,6,7};                           
    int num=sizeof(IntArr)/sizeof(int);                      
    MySort(IntArr,num);
    PrintArray(IntArr,num);
}

int main()
{
    // test01();
    test02();
}