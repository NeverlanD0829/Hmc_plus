/*
    4.2谓词
    返回bool类型的放函数称为谓词
        4.2.1概念
            如果operator（）接受一个参数，叫做一元谓词
            如果operator（）接受两个参数，叫做二元谓词
        4.2.2 一元谓词


*/
#include<iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

class GreaterFive
{
    public:
        bool operator()(int val)const           //一元谓词
        {
            return val>5;
        }
};
void test01()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }

    //GreaterFive()  是匿名函数对象
    //查找容器中有无大于5的数字
    vector<int>::iterator it=find_if(v.begin(),v.end(),GreaterFive());          //按条件查找
    if(it==v.end())
    {
        cout<<"未找到"<<endl;
    }
    else
    {
        cout<<"找到"<<(*it)<<endl;
    }
}

int main()
{
    test01();
}