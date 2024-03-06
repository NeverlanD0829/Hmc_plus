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

void swap1(int a,int b)                 //值传递
{
    int temp=0;

    temp=a;
    b=a;
    b=temp;
}

void swap2(int *p1,int *p2)                 //地址传递
{
    int temp=0;

    temp=*p2;
    *p2=*p1;
    *p1=temp;
}




int main()
{
    int a=100;
    int b=200;

    //swap1(a,b);

    swap2(&a,&b);

    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;



    system("pause");
    return 0;
}


//技巧：看const右侧紧跟着的是指针还是常量, 是指针就是常量指针，是常量就是指针常量
//总结：如果不想修改实参，就用值传递，如果想修改实参，就用地址传递

