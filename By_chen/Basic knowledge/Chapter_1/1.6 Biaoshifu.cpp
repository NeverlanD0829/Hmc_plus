//标识符命名规则：
//1.标识符不能是关键词
//2.标识符只能由字母、数字、下划线组成
//3.第一个字符必须为字母或下划线
//4.标识符区分大小写

#include <iostream>
using namespace std;

int main()
{
    //1.标识符不能是关键词
    //int int=10;

    //2.标识符只能由字母、数字、下划线组成
    int a=10;
    int a_10=20;
    int _a12=30;

    //3.第一个字符必须为字母或下划线
    //int 123abc=40;

    //4.标识符区分大小写
    int AAA=123;
    int aaa=456;


    cout<<a<<endl;
    cout<<a_10<<endl;
    cout<<AAA<<endl;

    system("pause");
    return 0;
}