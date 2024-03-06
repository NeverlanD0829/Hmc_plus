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
    3.1.5 string查找和替换
        功能：查找字符串是否存在
        替换：在指定位置替换字符串

        int find(const string& str, int pos = 0) const;         //查找str第一次出现位置从pos开始查找
        int find(const char* s, int pos = 0) const;             //查找s第一次出现位置从pos开始查找
        int find(const char* s, int pos, int n) const;          //从pos位置查找s的前n个字符第一次位置
        int find(const char C，int pos = 0) const;              //查找字符c第一次出现位置
        int rfind(const string& str, int pos = npos) const;     //查找str最后一次位置从pos开始查找
        int rfind(const char* s，int pos = npos) const;         //查找s最后一次出现位置从pos开始查找
        int rfind(const char* s, int pos, int n) const;         //从pos查找s的前n个字符最后一次位置
        int rfind(const char C, int pos = 0) const;             //查找字符c最后一次出现位置
        string& replace(int pos, int n, const string& str);     //替换从pos开始n个字符为字符串str
        string& replace(int pos, int n,const chan* s);          //替换从pos开始的n个字符为字符串s

        find查找是从左往后，rfind从右往左
        find找到字符串后返回查找的第一个字符位置 ，找不到返回-1
        replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串
    3.1.6 string字符串比较
        功能描述：
            字符串间比较：字符串比较是按字符的ASCII码进行对比.
            =返回 0
            >返回 1
            <返回 -1
        int compare(const string &s) const;             //与字符串s比较
        int compare(const char *s) const;               //与字符串s比较
    3.1.7 string字符串存取
            //字符串存取
            // char& operator[](int n) 通过[]方式存取字符
            // char& at(int n) 通过at方法获取字符
    3.1.8 对string字符串进行插入和删除字符操作
            string& insert(int pos ,const char* s);//插入字符串
            string& insert(int pos， int n， char c);/l在指定位置插入n个字符c
            string& erase(int pos， int n = npos);//删除从Pos开始的n个字符
    3.1.9 string字串
            string substr(int pos=0,int n=npos)const 返回由pos开始的n个字符组成的字符串。
*/

#include <iostream>
#include <string>
using namespace std;

//比较字符串
void test06()
{
    string str="abcdefg";
    string substr=str.substr(1,3);          //返回pos开始的n个字符组成的字符串
    cout<<"substr="<<substr<<endl;
}

void test07()
{
    string email="chen1449262967@163.com";
    int pos=email.find("@");
    string name=email.substr(0,pos);
    cout<<"name="<<name<<endl;
}

int main()
{
    test06();
    test07();
}