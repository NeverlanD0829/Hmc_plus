/*
    算法主要由头文件：<algorithm>/<functional>/<numeric> 组成
        <algorithm>:所有STL头文件中最大的一个，范围涉及到：比较/交换/查找/遍历/复制/修改等等。
        <numeric>:体积很小，自包括几个在序列上进行简单数学运算的模版函数。
        <functional>:定义一些类模版，用以声明函数对象。
    5.1常用遍历算法
        5.1.1 for_each（遍历容器）
            for_each(iterator beg,iterator end,_func);
                beg:起始迭代器   end：结束迭代器     _func:函数或函数对象


*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void Print(int val)
{
    cout<<val<<" ";
}

class Print02
{
    public:
        void operator()(int val)
        {
            cout<<val<<" ";
        }
};

void test01()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(),v.end(),Print);              //普通函数遍历，传入函数名就行
    cout<<endl;

    for_each(v.begin(),v.end(),Print02());          //匿名函数对象，需要传入函数对象
    cout<<endl;
}

int main()
{
    test01();

}