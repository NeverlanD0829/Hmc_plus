#include <iostream>
#include <string>
using namespace std;

//
int main()
{
    //代表真或假的值     true（本质是1），false（本质是0）。 bool类型占一个字节的大小

    bool flag=true;
    cout<<flag<<endl;


    flag=false;
    cout<<flag<<endl;

    cout<<"size of flag="<<sizeof(flag)<<endl;

    system("pause");
    return 0;
}