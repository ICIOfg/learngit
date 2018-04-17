 ///
 /// @file    Point3.cc
 /// @author  ICIOfg
 /// @date    2018-04-12 23:00:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	int _ix;
	int _iy;

	public:
		Point()
		: _ix(0)
		, _iy(0)
		{
			cout << "Point()" << endl;
		}
		explicit   //禁止隐式转换  implicit
		Point( int x, int y =0)
		: _ix(x)
		, _iy(y)
		{
			cout << "Point(int, int)" << endl;
		}

		void print()
		{
			cout << "(" << _ix
				<< "," << _iy
				<< ")" << endl;
		}

};

int main(void)
{
	int arr[5];
	Point points[5] = { Point(1,1), Point(3,3)};

	Point pt =1; // 隐式转换 ,通过构造函数，类似
			// Point pt(1);
	pt.print();

	return 0;
}

