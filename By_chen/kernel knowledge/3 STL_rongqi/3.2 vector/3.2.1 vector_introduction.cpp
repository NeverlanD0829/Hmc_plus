/*
    3.2.1 概念：
        功能：vector数据结构与数组非常相似，也称为单端数组
        vector与普通数组的区别：数组是静态空间，vector可以动态扩张
        动态扩展：
            并不是在原空间之后续新空间，而是找更大的内存空间，然后将数据拷贝至新空间，释放原空间。
            vector容器的迭代器是支持随机访问的迭代器。
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintVector(vector<int>& v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    vector<int> v1;                 //构造函数，默认构造
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    // PrintVector(v1);

    vector<int> v2(v1.begin(),v1.end());        //通过区间构造
    // PrintVector(v2);

    vector<int>v3(10,100);                      //10个100 方式构造
    PrintVector(v3);

    vector<int>v4(v3);                          //拷贝构造
    PrintVector(v4);    

}


int main()
{
    test01();
}