#pragma once       //预处理指令,确保头文件只被包含一次,防止多次被包含引起重定义
#include <iostream>
using namespace std;

template <class NameType,class AgeType>
class Person
{
public:
    //1.类模版成员函数类内实现
    // Person(NameType name,AgeType Age)
    // {
    //     this->m_Name=name;
    //     this->m_Age=Age;
    // }
    // void showPerson()
    // {
    //     cout<<"Name:\t"<<this->m_Name<<endl;
    //     cout<<"Age:\t"<<this->m_Age<<endl;
    // }

    // NameType m_Name;
    // AgeType m_Age;

    //2.类模版成员函数类外实现
    Person(NameType name,AgeType age);
    void showPerson();
    NameType m_Name;
    AgeType m_Age;
};