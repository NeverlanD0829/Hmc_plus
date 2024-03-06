/*
    3.7 Set容器简介：
        所有元素在插入时自动被排序
        本质：
            set/multiset 属于关联式容器，底层结构是二叉树实现。
        set、multiset 区别：
            set不容许容器中有重复的元素
            multiset允许容器中有重复的元素
    3.7.1 set构造和赋值
        set<T> st;//默认构造函数:
        set(const set &st);//拷贝构造函数
        赋值:
        set& operator=(const set &st);//重载等号操作符 
    3.7.2 set大小和交换
        size（）、empty（）、swap（st）     set容器不支持resize（）重新指定的大小
    3.7.3 插入和删除
        set和multiset的区别
            set 不可以插入重复的值  set插入数据的同时会返回插入结果 返回插入十分成功
            multiset 可以插入重复的值
        insert(elem);                       //在容器中插入元素。
        clear();                            //清除所有元素
        erase(pos);                         //删除pos迭代器所指的元素，返回下一个元素的迭代器。
        erase(beg,end);                     //删除区间[beg,end)的所有元素，返回下一个元素的迭代器。
        erase(elem);		                //删除容器中值为elem的元素。
    3.7.4 查找和统计
        find(key)       查找key是否存在 若存在 返回该键的元素的迭代器 若不存在 返回set.end()
        count(key)      统计key的元素个数
    3.7.5 set和multiset的区别
            set         不可以插入重复的值  set插入数据的同时会返回插入结果 返回插入十分成功
            multiset    不会检测数据，因此可以插入重复的值

*/
#include <iostream>
#include <string>
#include <set>
using namespace std;

void PrintSet(multiset<int> &s)
{
    if(!s.empty())
    {
        for(set<int>::const_iterator it=s.begin();it!=s.end();it++)
        {
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"set容器为空"<<endl;
    }
    
}

void test01()
{
    set<int> s;                                            //特点：所有元素插入时自动排序，且不允许插入重复的数据。
    pair<set<int>::iterator,bool>ret=s.insert(10);         //对组  insert调用时，返回值类型是pair，pair包含迭代器和bool类型
    if(ret.second)                                         //ret.second是布尔类型
    {
        cout<<"第一次插入成功"<<endl;
    }
    else{
        cout<<"第一次插入失败"<<endl;
    }

    ret=s.insert(10);
    if(ret.second)                                         //ret.second是布尔类型
    {
        cout<<"第二次插入成功"<<endl;
    }
    else{
        cout<<"第二次插入失败"<<endl;
    }


    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    for(multiset<int>::iterator it=ms.begin();it!=ms.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

}

int main()
{

    test01();
    return 0;
}