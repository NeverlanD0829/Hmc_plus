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
        1.2.5 普通函数和函数模版的调用规则
            1.如果函数模版和普通函数都可以实现,优先使用普通函数
            2.可以通过空模版参数列表来强制调用函数模版
            3.函数模版也可以发生重载
            4.如果函数模版可以产生更好的匹配,优先调用函数模版
            注意:如果提供了模版,就不要提供普通函数版本,容易出现二义性.
        1.2.6 模版的局限性
            模版不是万能的,有些特定的数据类型,需要具体化方式做特殊实现
            模版的重载,为特定类型提供具体化的模版.
    1.3 类模版
        1.3.1类模版的语法
            作用:建立一个通用类,类中的成员,数据类型可以不具体指定,用一个虚拟的类型来代表.
        1.3.2 类模版与函数模版的区别
            类模版没有自动类型推导的使用方式,必须显示指定类型.
            类模版在模版参数列表中可以有默认参数
        1.3.3 类模版中成员函数创建时机
            类模版中成员函数和普通类中成员函数创建市级是有区别的:
                普通类中的成员函数一开始就可以创建
                类模版中的成员函数在调用时创建
        1.3.4 类模版对象做函数参数
            类模版实力化出的对象,向函数传参的方式
            三种传入方式:
                1.指定传入类型,最常用
                2.参数模版化
                3.整个类模版化
            查看类型:
                cout<<typeid(NameType).name()<<endl;


*/

#include <iostream>
#include <string>
using namespace std;

template <class NameType,class AgeType>
class Person
{
    public:
        Person(NameType name,AgeType age)
        {
            this->m_Name=name;
            this->m_Age=age;
        }
        void ShowPerson()
        {
            cout<<"Name:\t"<<this->m_Name<<endl;    
            cout<<"Age:\t"<<this->m_Age<<endl;       
        }
        NameType m_Name;
        AgeType m_Age;
};

//1.指定传入数据类型(最常用)
void PrintPerson1(Person<string,int> &p)                        //函数接受传入引用类型参数,参数类型是Person<string,int>。而 <string, int> 是模板参数
{
    p.ShowPerson();
}   

// 2.参数模版化
template <class NameType,class AgeType>
void PrintPerson2(Person<NameType,AgeType> &p)
{
    p.ShowPerson();
    cout << "NameType" << typeid(NameType).name() << endl;      // 查看type类型     typeid 是 C++ 中的一个运算符，允许您获取关于表达式或类型的信息。它是由 typeinfo 头文件提供的类型识别功能的一部分。
    cout<<"AgeType:"<<typeid(AgeType).name()<<endl;
}

//3.整个类模版化
template <class T>
void PrintPerson3(T &p)
{
    p.ShowPerson();
    cout<<"NameType:"<<typeid(T).name()<<endl;
}

void test01()
{
    Person<string,int> p1("sun",19);
    PrintPerson1(p1);
    PrintPerson2(p1);
    PrintPerson3(p1);
}

int main()
{   
    test01();
}