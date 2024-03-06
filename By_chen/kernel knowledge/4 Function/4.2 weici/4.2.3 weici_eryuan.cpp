/*
    4.2谓词
    返回bool类型的放函数称为谓词
        4.2.1概念
            如果operator（）接受一个参数，叫做一元谓词
            如果operator（）接受两个参数，叫做二元谓词
        4.2.2 一元谓词
        4.2.3 二元谓词


*/
#include<iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

class Mysort
{
    public:
        bool operator()(int val1,int val2)           //一元谓词
        {
            return val1>val2;
        }
};
void test01()
{
    vector<int>v;
    v.push_back(13);
    v.push_back(23);
    v.push_back(43);
    v.push_back(63);
    v.push_back(33);
    v.push_back(53);
    sort(v.begin(),v.end());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    //使用函数对象，改变算法策略，变为排序规则从小到大
    sort(v.begin(),v.end(),Mysort());
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
}

int main()
{
    test01();
}