/*
    3.4 stack容器
        3.4.1 stack容器基本概念
            stack是先进先出的数据结构，不允许有遍历行为，只能对栈顶进行操作。
            栈可以判断容器是否为空empty。
            栈可以返回元素个数。

        3.4.2 stack常用接口
            栈：先进先出，不允许遍历
            
            构造函数：
                stack<T>                                stack采用模版类实现，stack对象的默认构造形式
                stack（const stack &stk）               拷贝构造函数
            赋值操作：
                stack& operator=（const stack &stk）    重载=运算符
            数据存取：
                push（elem）；                          栈顶添加元素
                pop（）；                               栈顶移除元素                                 
                top（）；                               返回栈顶元素
            大小操作：
                empty（）；                             判断堆栈是否为空
                size（）；                              返回栈的大小
*/

#include <iostream>
#include <stack>
using namespace std;

void test01()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<"栈的大小："<<s.size()<<endl;
    while(!s.empty())
    {
        cout<<"栈顶元素为："<<s.top()<<endl;
    //出栈
        s.pop();
    }
    cout<<"栈的大小："<<s.size()<<endl;
}

int main()
{
    test01();
    return 0;
}
