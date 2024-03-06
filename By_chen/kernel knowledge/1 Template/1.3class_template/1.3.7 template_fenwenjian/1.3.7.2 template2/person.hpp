// #pragma once       
#ifndef PERSON_H  
#define PERSON_H                  
/*
#pragma once  预处理指令,确保头文件只被包含一次,防止多次被包含引起重定义.使用此会产生报警.

#ifndef PERSON_H 这样的头文件守卫确保在同一编译单元中多次包含头文件时，只有一份实体会被编译。这有助于避免重定义错误。
如果你有多个头文件，你应该为每个头文件使用唯一的宏名称，以防止宏之间的冲突。
例如，可以在每个头文件中使用类似 PERSON_H 的宏名称。采用传统的头文件守护.
如果宏PERSON_H未被定义,则执行下面的代码.

#define PERSON_H
*/
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

template <class T1,class T2>
Person<T1,T2>::Person(T1 name,T2 age)
{
    this->m_Name=name;
    this->m_Age=age;
}

template<class T1,class T2>
void Person<T1,T2>::showPerson()
{
    cout<<"Name:\t"<<this->m_Name<<endl;
    cout<<"Age:\t"<<this->m_Age<<endl;
}


#endif // PERSON_H          //结束宏