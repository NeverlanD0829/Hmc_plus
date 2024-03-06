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
            cout<<this->m_Name<<endl;
            cout<<this->m_Age<<endl;
        }

    NameType m_Name;
    AgeType m_Age;
};


void test01()
{
    Person<string,int>  p1("呆子",20);
    p1.ShowPerson();
}

int main()
{   
    test01();
    // test02();
}