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
        5.1.1写文件
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

*/

#include <fstream>                          //1、包含头文件
#include <iostream>
using namespace std;
void test01()
{
    fstream ofs;                            //2、创建流对象
    ofs.open("E:/C++/By_chen/Advanced knowledge/chapter_5/test.txt",ios::out);          //3、打开文件

    ofs<<"姓名：郑"<<endl;                  //4、写入数据
    ofs<<"性别：男"<<endl;
    ofs<<"年龄：18"<<endl;
    ofs.close();                           //5、关闭文件
}

int main()
{
    test01();
    system("pause");
    return 0;
}

/*
    总结：
        1.文件操作必须包含头文件(fstream)
        2.读文件可以利用 ofstream、或者fstream。一般用fstream，因为fstream既可以读也可以写。
        3.打开文件时需要指定文件路径，及打开方式。
        4.利用  <<  操作符可以向文件中写入数据。
        5.操作完毕要关闭文件


*/