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
		

		//复制构造函数，
		//如果不自己提供，编译器会自动提供一个
		//
		//同构造函数，只是需传参，固定个数，种类
		Point(const Point & rhs)
		: _ix(rhs._ix)
		, _iy(rhs._iy)
		{
			cout << "Point( const Point & rhs) " << endl;
		}

		



		~Point() //析构函数，清理函数空间
		{
			cout << "~Point()" << endl;
		}


	private:

		int _ix;
		int _iy;
};

void test()
{
	int a =1;
	int b = a;
	cout << "b=" << b << endl;
	int c(a);
	cout << " c= " << c << endl;

	Point p1(5,6);
	Point p2 = p1;
	cout << "p1=";
	p1.print() ;
	cout << " p2= ";
	p2.print() ;

}



int main(void)
{
	Point pt1;
	pt1.print();

	Point pt2( 3, 4);
	pt2.print();

	test();

	return 0;
}
