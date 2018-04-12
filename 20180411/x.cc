 ///
 /// @file    x.cc
 /// @author  ICIOfg
 /// @date    2018-04-11 20:31:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class X
{
	public:
//初始化成员时，成员初始化顺序只与其被声明时的顺序保持一致
//与其初始化列表中顺序无关
//此处根据声明顺序，先初始化_ix,得到随机的_iy值，再初始化_iy得到参数值2
		X(int iy)
		: _iy(iy)
		, _ix(_iy)
		{
		}

		void print()
		{
			cout << "(" << _ix << "," << _iy << ")" << endl;
		}

	private:
		int _ix;
		int _iy;
};

int main(void)
{
	X x(2);
	x.print();
	return 0;
}

