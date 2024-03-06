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
        1.2.4普通函数和模版函数的区别
            普通函数调用时可以发生自动类型转换(隐式类型转换)
            函数模版调用时,如果利用自动类型推导,不会发生隐式类型转换
            如果利用显示指定类型的方式,可以发生隐式类型转换



*/

#include <iostream>
#include <string>
using namespace std;

//普通函数
int MyAdd(int a,int b)
{
    return a+b;
}

//模版函数
template<class T>
T MyAdd02(T a,T b)
{
    return a+b;
}


void test01()
{
    int a=10;
    int b=20;
    char c='c';
    cout<<MyAdd(a,b)<<endl;
    cout<<MyAdd02(a,b)<<endl;
    cout<<MyAdd(a,c)<<endl;
    // cout<<MyAdd02(a,c)<<endl;           //错误,不会发生隐式类型转换
    cout<<MyAdd02<int>(a,c)<<endl;      //109. 发生隐式类型转换
    cout<<MyAdd02<char>(a,c)<<endl;      //m. 发生隐式类型转换,转换为字符型对应的ascii码
}


int main()
{
    test01();
    // test02();
}