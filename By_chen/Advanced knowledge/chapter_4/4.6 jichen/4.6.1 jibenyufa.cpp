/*
例如我们看到很多网站中，都有公共的头部，公共的底部，甚至公共的左侧列表，只有中心内容不同
接下来我们分别利用普通写法和继承的写法来实现网页中的内容，看一下继承存在的意义以及好处
*/


#include<iostream>
#include<string>
using namespace std;

//普通实现方法：
//Java页面
// class Java 
// {
// public:
// 	void header()
// 	{
// 		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
// 	}
// 	void footer()
// 	{
// 		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
// 	}
// 	void left()
// 	{
// 		cout << "Java,Python,C++...(公共分类列表)" << endl;
// 	}
// 	void content()
// 	{
// 		cout << "JAVA学科视频" << endl;
// 	}
// };
// //Python页面
// class Python
// {
// public:
// 	void header()
// 	{
// 		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
// 	}
// 	void footer()
// 	{
// 		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
// 	}
// 	void left()
// 	{
// 		cout << "Java,Python,C++...(公共分类列表)" << endl;
// 	}
// 	void content()
// 	{
// 		cout << "Python学科视频" << endl;
// 	}
// };
// //C++页面
// class CPP 
// {
// public:
// 	void header()
// 	{
// 		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
// 	}
// 	void footer()
// 	{
// 		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
// 	}
// 	void left()
// 	{
// 		cout << "Java,Python,C++...(公共分类列表)" << endl;
// 	}
// 	void content()
// 	{
// 		cout << "C++学科视频" << endl;
// 	}
// };

//继承实现方法：

class Basepage
{
    public:
    void header()
	{
		cout << "首页、公开课、登录、注册...（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}
	void left()
	{
		cout << "Java,Python,C++...(公共分类列表)" << endl;
	}
};

class Python:public Basepage
{
    public:
    void content()
	{
		cout << "Python学科视频" << endl;
	}
};

class Java:public Basepage
{
    public:
    void content()
	{
		cout << "Java学科视频" << endl;
	}
};

class CPP:public Basepage
{
    public:
    void content()
	{
		cout << "Cpp学科视频" << endl;
	}
};

void test01()
{
	//Java页面
	cout << "Java下载视频页面如下： " << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();
	cout << "--------------------" << endl;

	//Python页面
	cout << "Python下载视频页面如下： " << endl;
	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();
	cout << "--------------------" << endl;

	//C++页面
	cout << "C++下载视频页面如下： " << endl;
	CPP cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();

}

int main() 
{


	test01();

	system("pause");

	return 0;
}

