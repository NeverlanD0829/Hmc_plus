#include<iostream>
#include<string>
using namespace std;
#define MAX 1000



//退出功能：根据用户的不同选择，进入不同的功能，可以选择switch分支结构，搭建架构。用户选择0时退出，选择其他先不做操作。

//封装一个显示菜单的函数，在main函数中调用该函数
void showMenu()
{
    cout<<"***********************"<<endl;
    cout<<"*****1、添加联系人*****"<<endl;
    cout<<"*****2、显示联系人*****"<<endl;
    cout<<"*****3、删除联系人*****"<<endl;
    cout<<"*****4、查找联系人*****"<<endl; 
    cout<<"*****5、修改联系人*****"<<endl;
    cout<<"*****6、清空联系人*****"<<endl; 
    cout<<"*****0、退出通讯录*****"<<endl;                      
    cout<<"***********************"<<endl;  
    system("pause");
}

struct Person                   //联系人结构体
{
    string m_Name;
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct Addressbooks
{
    struct Person personArray[MAX];
    int m_size;                         //  通讯录中人员个数    
};


void addPerson(Addressbooks * abs)      //添加联系人！！！地址传递，采用指针接受该地址。
{
    //判断通讯录是否满了
    if(abs->m_size==MAX)                //在C++中，"->"是一个运算符，称为成员访问运算符，它用于通过指针访问指向对象的成员。
    {
        cout<<"通讯录已满，无法添加"<<endl;
        return;
    }
    else
    {
        //添加联系人姓名
        string name;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        abs->personArray[abs->m_size].m_Name=name;

        //添加联系人性别
        int sex;
        cout<<"请输入性别："<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        while(true)
        {
            cin>>sex;
            if (sex==1||sex==2)
            {
                abs->personArray[abs->m_size].m_Sex=sex;
                break;
            }
            else
            {
                cout<<"输入有误，请重新输入！！！"<<endl;
            }
        }

        
        //添加联系人年龄
        int age;
        cout<<"请输入年龄："<<endl;
        cin>>age;
        abs->personArray[abs->m_size].m_Age=age;


        //添加联系人电话号
        string phone;
        cout<<"请输入电话："<<endl;
        cin>>phone;
        abs->personArray[abs->m_size].m_Phone=phone;

        //添加联系人地址
        string Addr;
        cout<<"请输入地址："<<endl;
        cin>>Addr;
        abs->personArray[abs->m_size].m_Addr=Addr;

        //更新通讯录
        abs->m_size++;
        cout<<"添加成功"<<endl;

        system("pause");                                //按任意键继续
        system("cls");                                  //清屏操作
    }
}


void showPerson(Addressbooks * abs)                                       //显示所有的联系人
{
    //判断通讯录中人数是否为0，如果为0，提示记录为空
    //如果不为0，显示记录的联系人信息
    if(abs->m_size==0)
    {
        cout<<"当前记录为空"<<endl;
    }
    else
    {
        for(int i=0;i<abs->m_size;i++)
        {
            cout<<"姓名："<<abs->personArray[i].m_Name<<" \t";                       //  \t是转义字符，空8格
            cout<<"性别："<<(abs->personArray[i].m_Sex==1?"男":"女")<<" \t";
            cout<<"年龄："<<abs->personArray[i].m_Age<<" \t";
            cout<<"电话："<<abs->personArray[i].m_Phone<<" \t";
            cout<<"住址："<<abs->personArray[i].m_Addr<<endl;
        }
    }
    system("pause");
    system("cls");
}


//删除联系人            作用：按姓名删除指定的联系人
//步骤：封装检测联系人是否存在；封装删除联系人函数；测试删除联系人功能。


int isExist(Addressbooks *abs,string name)
{
    for(int i=0;i<abs->m_size;i++)
    {
        if (abs->personArray[i].m_Name==name)               //找到用户输入姓名
        {
            return i;
        }
    }
    return -1;                                              //遍历结束都没找到
}

void deletePerson(Addressbooks * abs)
{
    cout<<"请输入要删除的人的姓名"<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if(ret!=-1)                         //ret即找到人的下标
    {
        //查到此人，要进行删除操作
        for(int i=0;i<abs->m_size;i++)
        {
            //数据前移
            abs->personArray[i]=abs->personArray[i+1];
        }
        abs->m_size--;
        cout<<"删除成功"<<endl;
    }
    else
    {
        cout<<"查无此人"<<endl;
    }
    system("pause");
    system("cls");
}

void findPerson(Addressbooks * abs)                                 //查找联系人
{
    cout<<"请输入要查找的联系人："<<endl;
    string name;
    cin>>name;
    int k=isExist(abs,name);
    if(k!=-1)                                        //有这个人
    {
            cout<<"姓名："<<abs->personArray[k].m_Name<<" \t";
            cout<<"性别："<<(abs->personArray[k].m_Sex==1?"男":"女")<<" \t";
            cout<<"年龄："<<abs->personArray[k].m_Age<<" \t";
            cout<<"电话："<<abs->personArray[k].m_Phone<<" \t";
            cout<<"住址："<<abs->personArray[k].m_Addr<<endl;
    }
    else
    {
        cout<<"没有这个人"<<endl;
    }
    system("pause");
    system("cls");
}

void modify(Addressbooks * abs)                     //修改联系人   按照姓名重新修改指定联系人。   思路：用户查找联系人，成功则进行修改，查找失败则提示查无此人。
{
    cout<<"请输入要修改的联系人的姓名："<<endl;
    string name;
    cin>>name;
    int ret=isExist(abs,name);
    if(ret!=-1)                                        //有这个人
    {
        string name;
        cout<<"请输入修改后的姓名："<<endl;
        cin>>name;
        abs->personArray[ret].m_Name=name;

        //添加联系人性别
        int sex;
        cout<<"请输入修改后的性别："<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        while(true)
        {
            cin>>sex;
            if (sex==1||sex==2)
            {
                abs->personArray[ret].m_Sex=sex;
                break;
            }
            else
            {
                cout<<"输入有误，请重新输入！！！"<<endl;
            }
        }

        
        //添加联系人年龄
        int age;
        cout<<"请输入修改后的年龄："<<endl;
        cin>>age;
        abs->personArray[ret].m_Age=age;


        //添加联系人电话号
        string phone;
        cout<<"请输入修改后的电话："<<endl;
        cin>>phone;
        abs->personArray[ret].m_Phone=phone;

        //添加联系人地址
        string Addr;
        cout<<"请输入修改后的地址："<<endl;
        cin>>Addr;
        abs->personArray[ret].m_Addr=Addr;

        cout<<"Bingo，修改成功"<<endl;
    }
    else
    {
        cout<<"没有这个人"<<endl;
    }
    system("pause");
    system("cls");
}

void cleanPerson(Addressbooks * abs)                              ////清空联系人(逻辑清空)   思路：将通讯录记录的联系人的数量置为0，做逻辑清空。
{
    abs->m_size=0;
    cout<<"通讯录清空成功!"<<endl;
    system("pause");
    system("cls");
}

int main()
{
    Addressbooks abs;                //创建通讯录结构体变量
    abs.m_size=0;                    //结构体变量初始化

    int select=0;
    while(true)
    {
        showMenu();
        cin>>select;
        switch (select)
        {
        case 1:                      //添加联系人
            addPerson(&abs);         //采用地址传递，可以改变实参的值。   
            break;
        case 2:                      //显示联系人
            showPerson(&abs);
            break;
        case 3:                      //删除联系人
            {
                cout<<"请输入删除联系人的姓名："<<endl;
                string name;
                cin>>name;
                if(isExist(&abs,name)==-1)
                {
                    cout<<"查无此人"<<endl;
                }
                else
                {
                    cout<<"找到此人"<<endl;
                }
            }
            deletePerson(&abs);
            break;
        case 4:                      //查找联系人
            findPerson(&abs); 
            break;
        case 5:                      //修改联系人
            modify(&abs);
            break;
        case 6:                      //清空联系人
            cleanPerson(&abs);
            break;
        case 0:                      //退出通讯录

            cout<<"欢迎下次使用！！！"<<endl;
            system("pause");
            return 0;
        default:
            break;
        }
    }




    system("pause");
    return 0;
}