//数组就是一个集合，集合里存放相同类型的数据元素
//特点：数组中每个数据元素都是相同的数据类型；          数组是由连续的内存位置组成的；      数组名的命名规范与变量名命名规范一致，不要和变量重名

//语法： 数据类型 数组名[ 数组长度 ];
//      数据类型 数组名[ 数组长度 ] = { 值1，值2 ...};
//      数据类型 数组名[ ] = { 值1，值2 ...};

//冒泡排序：最常用的排序算法，对数组内元素进行排序
    //比较相邻的元素。如果第一个比第二个大，就交换他们两个。
    //对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值。
    //重复以上的步骤，每次比较次数-1，直到不需要比较


//案例: 将数组 { 4,2,8,0,5,7,1,3,9 } 进行升序排序!




#include<iostream>
#include<string>
using namespace std;



void paixu(int *arr,int len)                //  *的作用是指示参数 arr 是一个指针类型。这意味着该函数期望接受一个指向整数的指针作为参数。
{
    for(int i=0;i<len-1;i++)                //排序的总轮数
    {
        for(int j=0;j<len-i-1;j++)            //每一轮比较的次数
        {
            if(arr[j]>arr[j+1])
            {
                int a=0;
                a=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=a;
            }
        }
    }   
}

void print(int arr[],int len)
{
    for(int m=0;m<len;m++)
    {
        cout<<arr[m]<<" ";
    } 
}



int main()
{
    //统计整个数组在内存中的长度
    int arr[10]={ 4,2,8,0,5,7,1,3,9,7};

    int len=sizeof(arr)/sizeof(int);                    //统计字符长度，先通过数组名统计数组占内存，再统计int型占字节

    paixu(arr,len);
    print(arr,len);
 

    system("pause");
    return 0;
}