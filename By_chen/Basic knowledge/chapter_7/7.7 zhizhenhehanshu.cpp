//指针的作用： 可以通过指针间接访问内存
    // 内存编号是从0开始记录的，一般用十六进制数字表示
    // 可以利用指针变量保存地址

//语法：  数据类型 * 变量名；
//指针变量和普通变量的区别：
    //  指针变量存放的是地址，普通变量存放的是数据；
    //  指针变量通过  *  操作符操作指针变量指向的内存空间，该过程称为解应用。


//指针、数组、函数
//封装一个函数，利用冒泡排序，实现对整型数组的升序排序。    例如数组：int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };



#include<iostream>
using namespace std;

void maopao(int *arr,int len)                 //值传递
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            } 
        }
    }
}


void PrintArray(int arr[],int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int arr[10]={4,3,8,13,1,2,10,28,7,45};
    int len=sizeof(arr)/sizeof(int);

    maopao(arr,len);
    PrintArray(arr,len);




    system("pause");
    return 0;
}


//技巧：看const右侧紧跟着的是指针还是常量, 是指针就是常量指针，是常量就是指针常量
//总结：如果不想修改实参，就用值传递，如果想修改实参，就用地址传递

