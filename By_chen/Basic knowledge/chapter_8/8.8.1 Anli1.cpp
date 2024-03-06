// 设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。
    // 通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
    // 五名英雄信息如下：
    	// {"刘备",23,"男"},
		// {"关羽",22,"男"},
		// {"张飞",20,"男"},
		// {"赵云",21,"男"},
		// {"貂蝉",19,"女"},


#include<iostream>
#include<string>
using namespace std;

struct hero
{
    string name;
    int age;
    string sexy;
};

void paopao(hero arr[] , int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {   
            if(arr[j].age>arr[j+1].age)
            {
                int temp=arr[j+1].age;
                arr[j+1].age=arr[j].age;
                arr[j].age=temp;
            }
        }
    }
}

void print(hero arr[] , int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<"姓名："<<arr[i].name<<" 年龄："<<arr[i].age<<" 性别："<<arr[i].sexy<<endl;
    }
}


int main()
{
    struct hero arr[5]=
    {
        {"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"}
    };

    int len = sizeof(arr) / sizeof(hero); //获取数组元素个数

    paopao(arr,len);
    print(arr,len);

    system("pause");
    return 0;
}