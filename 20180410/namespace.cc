 ///
 /// @file    namespace.cc
 /// @author  ICIOfg
 /// @date    2018-04-10 10:31:31
 ///
 
#include <iostream>
using std::cout;
using std::endl;

namespace A
{
	int a = 99;
	void dispalyA()
	{
		cout << a <<endl;
	}
}

namespace B
{
	int b = 1000;
	void dispalyA()
	{
	};
}
		



int main(void)
{
	cout << "hello, world" << endl;
	int a;
	std::cin >> a;
	cout << a << endl;
	A::dispalyA();
    return 0;
}

