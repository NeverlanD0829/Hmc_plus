/*
    3.1.1string容器
        本质：string是C++风格的字符串，而string本质是一个类。
        string和char*的区别：
            char *是一个指针
            string 是一个类，类内封装了char，管理这个字符串，是 char *的一个容器
        特点：
            string内部封装了很多成员方法：查找（find）/拷贝（copy）/替换（replace）/插入（insert）
            string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内进行负责。
    3.1.2string 构造函数

*/


/*
string()                            创建空字符串
string(const char* s)               使用字符串s初始化
string(const string& str)           使用一个string对象初始化另一个string对象
string(int n,char c)                使用n个字符串c初始化

*/
#include <iostream>
#include <string>
using namespace std;


void test01()
{
    string s1;                      //创建空字符串

    const char* str="rghj";         //使用字符串s初始化
    string s2(str);
    cout<<"s2="<<s2<<endl;

    const string& str1="fghjk";     //使用一个string对象初始化另一个string对象
    string s3(str1);
    cout<<"s3="<<s3<<endl;

    string s4(5,'b');
    cout<<"s4="<<s4<<endl;
}

int main()
{

    test01();
    return 0;
}