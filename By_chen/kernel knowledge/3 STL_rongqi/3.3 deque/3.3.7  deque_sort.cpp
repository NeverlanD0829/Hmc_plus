/*
    3.2.1deque（双队列）容器
    功能：双端数组，对头端进行插入、删除操作
    deque与vector区别：
        vector对头部插入、删除效率低，数据量大
        deque相对来说，对头部的插入删除速度比vector快
        vector访问元素时的速度比deque快，这和两者内部实现有关
    原理：deque内部有中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据。
         中控器维护的是每个缓冲区的地址，是的使用deque时像一片连续的内存空间。
    deque中迭代器也是支持随机访问的。
    
    3.2.2 构造函数
        函数原型：
            deque<T>;                   默认构造
            deque(beg,end);             将区间元素拷贝给本身
            deque(n,num);               构造函数将n个elem拷贝给本身
            deque(const deque &deq);    拷贝构造函数
    3.3.3 赋值操作
        功能：给deque容器进行赋值
        函数原型：
            deque& operator=(const deque &deq);     //重载等号操作符
            assign(beg，end);                       //将[beg, end)区间中的数据拷贝赋值给本身。
            assign(n， elem);                       //将n个elem拷贝赋值给本身。
    3.3.4 deque大小操作
        功能：对deque容器的大小进行操作
        函数原型：
            deque.empty();			//判断容器是否为空
            deque.size();			//返回容器中元素的个数
            deque.resize(num);		//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
            deque.resize(num,elem); //如果容器变短，则末尾超出容器长度的元素被删除。
                                    //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
                                    //如果容器变短，则末尾超出容器长度的元素被删除。
        注意：deque容器没有容量capacity的概念。
    3.3.5 deque删除和插入
        作用：向deque容器中插入和删除数据

        函数原型：
            两端插入操作:
                push_back(elem);//在容器尾部添加—个数据
                push_front(elem);//在容器头部插入一个数据
                pop_back();//删除容器最后一个数据
                pop_front();//删除容器第一个数据

            指定位置操作:
                insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
                insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
                insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
                clear();//清空容器的所有数据
                erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
                erase(pos);//删除pos位置的数据，返回下一个数据的位置。
    3.3.6 deque数据存取
        功能：对deque中的数据的存取操作。
        函数原型：
            at(int idx)     返回所以dix所指的数据
            operator[];     返回所以dix所指的数据
            front();        返回容器中第一个数据元素
            back();         返回容器中最后一个数据元素
    3.3.7 deque排序
        功能：利用算法实现对容器排序
        算法：
            sort(iterator beg,iterator end)         //对beg和end区间内元素进行排序。

    3.3.8 案例-评委打分
        描述：有5名选手abcde，10个评委分别对每一名选手进行打分，去除最高分/最低分，取平均分。
        实现步骤：
            1.创建5名选手，放在vector中
            2.遍历vector容器，取出来每一个选手，执行for循环，把十个评分打分存在deque中
            3.sort算法对deque容器中分数排序，去除最高分和最低分，取平均
            4.deque容器遍历一遍，累加总分
            5.获取平均分
*/

#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
#include<time.h>
using namespace std;
//有5名选手，分别为：ABCDE,10个评委分别对每一名选手打分，去除最高分，最低分，取平均分
class Person
{
public :
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	int m_Score;
};

void CreatPerson(vector<Person>& v)
{
	string nameSeed="abcde";
    for(int i=0;i<5;i++)
    {
        string name="player ";
        name+=nameSeed[i];
        int score=0;
        Person p(name,score);
        v.push_back(p);
    }
}

void SetScore(vector<Person> &v)
{
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)          
    {
        deque<int>d;                                                        //评委打分放在deque数组中
        for(int i=0;i<10;i++)
        {
            int score=rand()%41 +60;                                         //产生60-100的随机数
            d.push_back(score);
        }
        //排序：
        cout<<"选手："<<it->m_Name<<"打分:"<<endl;
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
        {
            cout<<*dit<<" ";
        }
        cout<<endl;
        sort(d.begin(),d.end());                //排序

        d.pop_back();                           //去除最高分
        d.pop_front();                          //去除最高分

        int sum=0;
        for(deque<int>::iterator dit=d.begin();dit!=d.end();dit++)
        {
            sum+=*dit;
        }
        int avg=sum/d.size();
        it->m_Score=avg;
    }
}
void ShowScore(vector<Person> &v)
{
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"player"<<(*it).m_Name<<"得分："<<(*it).m_Score<<endl;
    }
} 
int main()
{
	srand((unsigned int) time(NULL));               //随机数种子

    //1.创建选手
    vector<Person> v;                               //存放选手的容器
    CreatPerson(v);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名"<<(*it).m_Name << "  ";
		cout << "分数" << (*it).m_Score << "  "<<endl;
	}

    //2.给选手打分
    SetScore(v);

    //3.显示得分
    ShowScore(v);
}
