 ///
 /// @file    clasScope.cc
 /// @author  ICIOfg
 /// @date    2018-04-18 21:24:14
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int x =100;
int z = 10;

class x
{
};

namespace wd
{
	int x =1;

	class Example 
	{
		public:
			Example(int _x)
			: x(_x)
			{
			}

			void print(int x)
			{
				cout << "形参 x=" << x << endl;
				cout << "Example::x =" << Example::x << endl;
				cout << "Example::x=" << this->x << endl;
				cout << "wd::x=" << wd::x << endl;
				cout << "全局变量x=" << ::x << endl;
			}
		private:
			int x;
	};
}

int main(void)
{
	wd::Example e(3);
	e.print(4);

	return 0;
}
