/* ASCII:0-31分配给控制字符，用于控制像打印机一些外围设备；  32-126分配给了能在键盘上找到的字符，查看或打印文档时就能看见。 */
#include <iostream>
using namespace std;

int main()
{
    //ASCII非打印控制字符，   表上0-31分配给了控制字符，用于控制打印机等外围设备。
    //32-126 分配给了能在键盘上找到的字符，当查看或者打印文档时就会出现。
    //变量用于显示单个字符，不可是字符串。    c/c++中字符型变量只占用1个字节。
    //字符型变量并不是把字符本身放到内存中存储，而是将对应的ASCII编码放入到存储单元

    char ch='a';    //必须用单引号，不可以用双引号  ，单引号内只能有一个字符，不能是字符串。
    //char ch2='abcd';
    //char ch3="b";   

    cout<<ch<<endl;
    cout<<(int)ch<<endl;   //查看a对应的ascii码
    cout<<sizeof(ch)<<endl;


    ch=97;
	cout << ch << endl;
    
    system("pause");
    return 0;
}