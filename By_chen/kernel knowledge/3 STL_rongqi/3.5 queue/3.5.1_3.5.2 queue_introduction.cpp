/*
    3.5.1 queue容器基本概念：
        先进先出，两个出口（stack是后进先出，一个出口）

        队列容器从一端新增元素，从另一端移除元素。
        队列中只有对头和队尾才可以被外界使用，队列不允许有遍历行为。
        队列中进数据称为——入队push。
    
    3.5.2 常用操作：

        queue<T> que;                           //queue采用模板类实现，queue对象的默认构造形式
        queue(const queue &que);                //拷贝构造函数

        赋值操作:
        queue& operator=(const queue &que);     //重载等号操作符

        数据存取:
        push(elem);                             //往队尾添加元素
        pop();                                  //从队头移除第一个元素
        back();                                 //返回最后一个元素
        front();                                //返回第一个元素

        大小操作:
        empty();                                //判断堆栈是否为空
        size();                                 //返回栈的大小
*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

//queue队列
class Person
{
    public:
        Person(string name,int age)
        {
            this->m_Name=name;
            this->m_Age=age;
        }
    string m_Name;
    int m_Age;
};

void test01()
{
    queue<Person>q;
    Person p1("男1",20);
    Person p2("男2",21);
    Person p3("男3",22);
    Person p4("男4",23);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    cout<<"队列的大小为："<<q.size()<<endl;             //返回栈的大小

    while(!q.empty())
    {
        cout<<"队头元素——姓名："<<q.front().m_Name<<"年龄："<<q.front().m_Age<<endl;
        cout<<"队尾元素——姓名："<<q.back().m_Name<<"年龄："<<q.back().m_Age<<endl;
        q.pop();
    }
    cout<<"队列的大小为："<<q.size()<<endl;
}


int main()
{
    test01();
    return 0;
}