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
        string()                            创建空字符串
        string(const char* s)               使用字符串s初始化
        string(const string& str)           使用一个string对象初始化另一个string对象
        string(int n,char c)                使用n个字符串c初始化

    3.1.3 string 赋值操作
        string& operator=(const char* s);         //char*类型字符串赋值给当前的字符串
        string& operator=(const string &s);       //把字符串s赋给当前的字符串
        string& operator=(char C);                //字符赋值给当前的字符串
        string& assign(const char *s);            //把字符串s赋给当前的字符串
        string& assign(const char *s, int n);     //把字符串s的前n个字符赋给当前的字符串
        string& assign(const string &s);          //把字符串s赋给当前字符串
        string& assign(int n，char C);             //用n个字符c赋给当前字符串
    3.1.4 string字符串拼接
        string& operator+=(const char* str);               //重载+=操作符
        string& operator+=(const char C);                  //重载+=操作符
        string& operator+=(const string& str);             //重载+=操作符
        string& append(const char *s);                     //把字符串s连接到当前字符串结尾
        string& append(const char *s， int n);              //把字符串s的前n个字符连接到当前字符串结尾
        string& append(const string &s);                    //同operator+=(const string& str)
        string& append(const string &s，int pos， int n);   //字符串s中从pos开始的n个字符连接到字符串结尾

*/



#include <iostream>
#include <string>
using namespace std;


void test01()
{
    string str1="wertyui";                         //重载+=操作符
    str1+="fghjkdfghj";
    cout<<"str1="<<str1<<endl;

    string str2="wert";                            //重载+=操作符
    str2 +="t";
    cout<<"str2="<<str2<<endl;

    string str3="fghjkl";                           //重载+=操作符
    str3+=str1;
    cout<<"str3="<<str3<<endl;

    string str4="wo";                               //把字符串s连接到当前字符串结尾
    str4.append("rtfghyu",4);                       //把字符串s的前n个字符连接到当前字符串结尾
    cout<<"str4="<<str4<<endl;

    str4.append(str2);                              //同operator+=(const string& str)
    cout<<"str4="<<str4<<endl;

    string str5="fghjkl";
    str5.append(str1,2,4);                           //字符串s中从pos开始的n个字符连接到字符串结尾,如从str1="wertyui"的r开始的4个字符。
    cout<<"str5="<<str5<<endl;

}

int main()
{
    test01();
    return 0;
}