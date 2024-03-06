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

        5.1.2 读文件
            步骤：
                1.包含头文件：  #include <fstream>
                2.创建流对象：  ifstream ifs;
                3.打开文件：    ifs.open("文件路径"，打开方式)；
                4.读数据：      四种方式读取
                5.关闭文件：    ifs.close();

    5.2 二进制文件
        以二进制的形式对文件进行写操作，打开方式主要为   ios::binary
        5.2.1写文件(步骤和文本文件的步骤一样)
            二进制方式写文件主要利用 流对象 调用成员函数 write
            函数原型：  ostream& write(const char * buffer,int len);
            参数解释：  字符指针buffer指向内存中一段存储空间，len是读取的字节数。




*/

#include <fstream>                          //1、包含头文件
#include <iostream>
using namespace std;


class Person
{
    public:
        char m_Name[64];            //最好不要用string  用字符数组代替
        int m_Age;
};



void test01()                       //二进制文件   写文件
{
    //2.创建输出流对象
    fstream ofs;      

    //3.打开文件
    ofs.open("By_chen/Advanced knowledge/chapter_5/5.2.1 erjinzhi_xiewenjian/person.txt",ios::out|ios::binary);     //创建了一个名为 ofs 的文件流对象，设置了打开文件的模式为输出模式 (ios::out) 和二进制模式 (ios::binary)。  | 是位或操作符。

    Person p={"张三",20};

    //4.写文件(关键步骤)
    ofs.write((const char *)&p,sizeof(p));          //函数原型：  ostream& write(const char * buffer,int len);

    //5.关闭文件
    ofs.close();
}


int main()
{
    test01();
    system("pause");
    return 0;
}

/*
    总结：
        文件输出流对象，可以通过write函数，以二进制方式写入数据
*/