#include <iostream>
using namespace std;

int main()
{
    //单精度float  占用4字节，   7位有效数字
    //双精度double 占用8字节，   15-16位有效数字

    //默认一个小数会输出六位有效数字
    
    float f1=3235763275.1415936785478f;             //一般在单精度数据后加f，如果不加，默认为双精度。
    double d1=3.1415936785478;

    cout<<f1<<endl;
    cout<<d1<<endl;

    cout.precision(10);                              //改变默认保留几位小数

    cout<<f1<<endl;
    cout<<d1<<endl;

    cout<<"float sizeof="<<sizeof(f1)<<endl;
    cout<<"doulle sizeof="<<sizeof(d1)<<endl;

    //科学计数法

    float f2=3e2;  //3*10^2
    cout<<"f2="<<f2<<endl;

    float f3=3e-2;  //3*10^2
    cout<<"f3="<<f3<<endl;
    
    system("pause");
    return 0;
}