 ///
 /// @file    namespace1.cc
 /// @author  ICIOfg
 /// @date    2018-04-10 22:34:42
 ///
 
#include <iostream>
using namespace std; //using 编译指令

namespace A //变量或者是函数或对象，都统称为命名空间中的实体
{
	int a = 10;
	void displayA()
	{
		cout << "A::dispalyA()" << endl;
	}
	namespace C
	{
		void displayC()
		{
			cout << "C::dispalyC()" << endl;
		}
	}
}

namespace B
{
	int a = 20;
}

void cout()
{
}

int main(void)
{
	//作用域限定符
	A::displayA();
	A::C::displayC();

//	cout();//实体的二义性

	return 0;
}

