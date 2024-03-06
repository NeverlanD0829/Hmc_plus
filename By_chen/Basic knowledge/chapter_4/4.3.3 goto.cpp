#include <iostream>
#include <string>
using namespace std;


//作用：可以无条件跳转语句
//语法：goto 标记;
//如果标记的名称存在，执行到goto语句时，会跳转到标记的位置

//在程序中不建议使用goto语句，以免造成程序流程混乱
int main() {
 
	cout << "1" << endl;
 
	goto FLAG;
 
	cout << "2" << endl;
	cout << "3" << endl;\


    FLAG:
	cout << "4" << endl;
	cout << "5" << endl;
	
	system("pause");
 
	return 0;
}
  