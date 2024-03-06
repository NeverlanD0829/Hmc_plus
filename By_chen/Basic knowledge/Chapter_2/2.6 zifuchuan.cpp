#include <iostream>
#include <string>
using namespace std;

//
int main()
{
    //C风格:      char 变量名[]="字符串值"
    char str1[]="hello worrld";
    cout<<"C风格的字符串:"<<str1<<endl;
    

    //C++风格： string str ="字符串值"      字符用单引号，字符串用双引号。

    string str2="Hello world";
    cout<<"C++风格的字符串:"<<str2<<endl;

    system("pause");
    return 0;
}