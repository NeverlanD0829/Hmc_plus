#include <iostream>
#include <string>
#include "MyArray.hpp"
using namespace std;
void printIntArray(MyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}

void test01()
{
    MyArray<int> arr1(5); // 有参构造
    // MyArray<int> arr2(arr1); // 拷贝构造
    // MyArray<int> arr3(100);
    // arr3 = arr1; //=重载
    // for (int i = 0; i < 5; i++)
    // {
    //     arr1.Push_Back(i);
    // }
    // cout << "arr1" << endl;
    // printIntArray(arr1);
    // cout << "大小：" << arr1.getCapacity() << "容量" << arr1.getSize() << endl;
    // arr1.Pop_back();
    // cout << "大小：" << arr1.getCapacity() << "容量" << arr1.getSize() << endl;
}
int main()
{
    test01();
}
