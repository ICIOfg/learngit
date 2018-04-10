 ///
 /// @file    namespace1.cc
 /// @author  ICIOfg
 /// @date    2018-04-10 22:34:42
 ///
 
#include <iostream>
//using namespace std; //using 编译指令

namespace A //变量或者是函数或对象，都统称为命名空间中的实体
{
	int a = 10;
	void displayA()
	{
		std::cout << "A::dispalyA()" << std::endl;
	}
	namespace C
	{
		void displayC()
		{
			std::cout << "C::dispalyC()" << std::endl;
		}
	}
}

namespace B
{
	int a = 20;
}

void cout()
{
	std::cout << "cout()--> hello" << std::endl;
}

int main(void)
{
	//作用域限定符
	A::displayA();
	A::C::displayC();

	cout();//实体的二义性

	return 0;
}

