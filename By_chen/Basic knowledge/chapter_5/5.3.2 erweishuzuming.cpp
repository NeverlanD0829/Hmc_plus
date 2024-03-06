//二维数组数组名作用
    // 查看二维数组所占内存空间
    // 获取二维数组首地址



#include<iostream>
#include<string>
using namespace std;


int main()
{
    //统计整个数组在内存中的长度
    int arr[2][3]={1,2,3,4,5,6};

    cout<<"二维数组大小："<<sizeof(arr)<<endl;                          //对二维数组名进行sizeof时，可以获取整个二维数组占用的内存空间大小
    cout<<"二维数组一行的大小："<<sizeof(arr[0])<<endl; 
    cout<<"二维数组单个元素的大小："<<sizeof(arr[0][0])<<endl;             
    cout<<endl;

    cout<<"数组中的行数是："<<sizeof(arr)/sizeof(arr[0])<<endl;
    cout<<"数组中的列数是："<<sizeof(arr[0])/sizeof(arr[0][0])<<endl;
    cout<<endl; 

    //通过数组名获取到数组地址
    cout << "数组首地址为： " << arr << endl;                           //二维数组名就是这个数组的首地址
	cout << "数组中第一行地址为： " << &arr[0] << endl;                 //直接打印数组名，可以查看数组所占内存的首地址
	cout << "数组中第二行地址为： " << &arr[1] << endl;
    cout<<endl; 

    cout << "二维数组第一个元素地址：" << &arr[0][0] << endl;
	cout << "二维数组第二个元素地址：" << &arr[0][1] << endl;
    cout<<endl; 

    system("pause");
    return 0;
}