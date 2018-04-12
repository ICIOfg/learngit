 ///
 /// @file    Point.cc
 /// @author  ICIOfg
 /// @date    2018-04-11 20:49:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
//构造函数可以重载
//
//没有构造函数时，编译器会提供一个默认构造函数,无参，初始化为随机值
#if 0
		Point()
		{
			_ix = 0;
			_iy = 0;
			cout << "Point()" << endl;
		}

		Point (int ix, int iy = 0)
		{
			cout << " Point( int , int)" << endl;
			_ix = ix;
			_iy = iy;
		}
#endif
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
//	Point pt1(1,2);
//	pt1.print();

	Point pt2;
	pt2.print();

//	Point pt3(3);
//	pt3.print();

	return 0;
}
