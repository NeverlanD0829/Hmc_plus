/*
    算法主要由头文件：<algorithm>/<functional>/<numeric> 组成
        <algorithm>:所有STL头文件中最大的一个，范围涉及到：比较/交换/查找/遍历/复制/修改等等。
        <numeric>:体积很小，自包括几个在序列上进行简单数学运算的模版函数。
        <functional>:定义一些类模版，用以声明函数对象。
    5.1常用遍历算法
        5.1.1 for_each（遍历容器）
            for_each(iterator beg,iterator end,_func);
                beg:起始迭代器   end：结束迭代器     _func:函数或函数对象

        5.1.2 transform
            将一个容器搬运到另一个容器
            原型：
                transform(iterator beg1,iterator end1,iterator beg2,_func)
            beg1:源容器开始迭代器
            end1:源容器结束迭代器
            beg2:目标容器起始迭代器
            _func:函数或函数对象
    5.2常用查找算法
        5.2.1 find
            find 查找指定元素 找到返回指定元素的迭代器 找不到返回end()迭代器。
        5.2.2 find_if
            find_if 按条件查找，返回迭代器
        5.2.3 adjacent_find   
            查找相邻的重复元素，返回相邻重复元素第一个位置的迭代器
        5.2.4 count
            统计元素个数
            count(begin,end,value)
        5.2.5 count_if
            按条件统计指定元素个数----谓词
        5.2.6 binary_search
            按元素查找，有序方可查找。
    5.3 常用排序算法
        5.3.1 sort
           sort():对容器内元素进行排序 
        5.3.2 shuffle
            洗牌，指定范围内元素随机调整持续
            default_random_engine engine(time(0));
        5.3.3 merge
            两容器合并，存储到另一个外容器中
            两个容器必须为有序的。 
        5.3.4 reverse 
            reverse 反转容器内元素
    5.4 常用拷贝和替换算法
        5.4.1 copy
            copy(v.begin(),v.end(),v2.begin());
        5.4.2 replace()
            replace()           将指定区间范围内的旧元素替换为新元素
            replace(begin,end,oldvalue,newvalue)
        5.4.3 replace_if
            replace_if(begin,end，谓词（条件），newvalue) 将指定区间范围内满足条件的元素 替换为新元素
        5.4.4 swap
            swap(container c1,container c2) 互换两个容器中的所有元素 同种类型的容器
    5.5 常用算术生成算法
        5.5.1 accumulate
            使用时包含的头文件为：
                #include <numerical>
        5.5.2 fill
            向容器中填充指定元素
    5.6 常用集合算法
        5.6.1 set_intersection
            求两个容器的交集，两个容器必须有序。
        5.6.2 set_union
            求两个容器的并集 两个容器必须有序。
        5.6.3 set_difference
            求两个容器的差集 两个容器必须有序
            A：0 1 2 3 4 5 6 7 8 9
            B：5 6 7 8 9 10 11 12 13 14
            差集，即A-B，属于A，但不属于B的元素，即 0 1 2 3 4 
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include <numeric>
using namespace std;

void Print(vector<int> &v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void myPrint(int val)
{
	cout << val << " ";
}
void test01()                                           
{
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    Print(v1);
    Print(v2);

    vector<int>vTarget;
    vTarget.resize(min(v1.size(),v2.size()));
    vector<int>::iterator itEnd=set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
    for_each(vTarget.begin(), itEnd, myPrint);                      //必须用myPrint这种输出，Print输出时，容器大小已经固定了。
}

int main()
{
    test01();
}