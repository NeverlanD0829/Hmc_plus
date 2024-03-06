/*
    文件操作：程序运行时产生的数据都属于临时数据，程序一旦运行结束就会被释放。
    文件作用：通过文件将数据持久化。
    文件操作头文件：    <fstream>
    文件类型：
        1、文本文件：文件以文本的ASCII码形式储存在计算机中。
        2、二进制文件：文件以文本的二进制形式储存在计算机中，用户一般不能直接读他们。
    文件的操作：
        1、ofstream:写操作(output file stream)
        2、ifstream:读操作(input file stream)
        3、fstream：读写操作
    
    5.1文本文件
        5.1.1 写文件
            步骤：
                1.包含头文件：  #include <fstream>
                2.创建流对象：  ofstream ofs;
                3.打开文件：    ofs.open("文件路径"，打开方式)；
                4.写数据：      ofs<<"写入的数据"；
                5.关闭文件：    ofs.close();

            文件打开方式：
                ios::in         为读文件而打开文件
                ios::out        为写文件而打开文件
                iOS::ate        初始位置：文件尾
                ios::app        追加方式写文件
                ios::turnc      如果文件存在先删除，再创建
                ios::binary     二进制方式
            注意：文件打开方式可以配合使用，利用 |(位或)操作符。
            例如：用二进制方式写文件           ios::binary|ios::out

        5.2.1 读文件
            步骤：
                1.包含头文件：  #include <fstream>
                2.创建流对象：  ifstream ifs;
                3.打开文件：    ifs.open("文件路径"，打开方式)；
                4.读数据：      四种方式读取
                5.关闭文件：    ifs.close();


*/

#include <fstream>                          //1、包含头文件
#include <iostream>
using namespace std;


void test01()
{
    ifstream ifs;                            //2、创建流对象
    ifs.open("By_chen/Advanced knowledge/chapter_5/5.1.2 duwenjian/test.txt",ios::in);          //3、打开文件
    if (!ifs.is_open())                     //.is_open()是类fstream的成员函数， !ifs.is_open() 是对 ifs.is_open() 的逻辑取反操作。如果 ifs.is_open() 返回 true，表示文件流已经成功打开；而 !ifs.is_open() 返回 false，表示文件流没有打开或者打开失败。
    {
        cout<<"文件打开失败"<<endl;
        return;
    }

    //第一种方式
    // char buf[1024]={0};                    // 把文件中的内容全部放在字符数组中，声明一个长度为 1024 的字符数组 buf，并初始化为全 0
    // while (ifs>>buf)                       // 通过流提取运算符 >> 将文件内容读入 buf 中
    // {
    //     cout<<buf<<endl;                   // 输出读取的内容到控制台
    // }
    
    // 第二种方式
    // char buf[1024]={0};                       // 声明一个长度为 1024 的字符数组 buf，并初始化为全 0
    // while(ifs.getline(buf,sizeof(buf)))       // 通过 getline() 函数将文件内容按行读入 buf 中,getline()函数传入两个参数，数组名 及 数组首地址
    // {
    //     cout<<buf<<endl;
    // }

    // 第三种方式（逐个字符输出，慢，不推荐）
    // char c;                                      // 声明一个字符变量 c
    // while ((c=ifs.get())!=EOF)                   // 逐字符地从文件中读取内容，直到文件末尾.EOF=end of file
    // {
    //     cout<<c;
    // }

    第四种方式
    string buf;                                     // 声明一个 string 类型的变量 buf，用于存储读取的每一行内容
    while (getline(ifs,buf))                        // 使用 getline() 函数从文件流中逐行读取内容，存储到 buf 中,getline()函数传入两个参数，既  流对象  和  字符串变量
    {
        cout<<buf<<endl;
    }
    
    

    ifs.close();                           //5、关闭文件
}

int main()
{
    test01();
    system("pause");
    return 0;
}

/*
    总结：
        1.读文件可以利用ifstream(fstream),或者fstream类
        2.利用is_open函数可以判断文件是否打开成功
        3.close关闭文件
*/