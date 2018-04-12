 ///
 /// @file    Point2.cc
 /// @author  ICIOfg
 /// @date    2018-04-11 21:21:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Point
{
	public: //初始化表达式
		Point()
		: _ix(0)
		, _iy(0)
		{
			cout << "Point()" << endl;
		}

		Point( int ix, int iy)
		: _ix(ix)
		, _iy(iy)
		{
			cout << "Point( int, int) " << endl;
		}

		void print()
		{
			cout << "(" << _ix << "," << _iy << ")" << endl;
		}

		~Point() //析构函数，清理函数空间
		{
			cout << "~Point()" << endl;
		}


	private:

		int _ix;
		int _iy;
};

int main(void)
{
	Point pt1;
	pt1.print();

	Point pt2( 3, 4);
	pt2.print();

	return 0;
}
