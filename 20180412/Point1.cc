 ///
 /// @file    Point1.cc
 /// @author  ICIOfg
 /// @date    2018-04-12 22:28:13
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	private:
		const int _ix;
		const int _iy;
		double & _refx;

	public:
// const型 与 引用型 都只能在初始化列表中初始化
		Point(int x, int y , double & refx)
		: _ix(x)
		, _iy(y)
		, _refx( refx)
		{
			cout << "Point( int , int , double &)" << endl;
		}

		void print()
		{
			cout << "(" << _ix
				<< "," << _iy
				<< "," << _refx
				<< ")" << endl;
		}

};

int main(void)
{
	double refx = 3.3;
	Point p1( 2, 2, refx);
	p1.print();

	refx = 6.6;
	p1.print();

	return 0;
}

	




