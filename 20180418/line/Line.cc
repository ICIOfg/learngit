 ///
 /// @file    Line.cc
 /// @author  ICIOfg
 /// @date    2018-04-18 22:46:31
 ///
#include "Line.h" 
#include <iostream>
using std::cout;
using std::endl;

class Line::LineImpl
{
	class Point
	{
		public:
			Point(int x, int y)
			: _x(x)
			, _y(y)
			{
			}

			void print()const
			{
				cout << "(" << _x << "," << _y << ")" <<endl;
			}

		private:
			int _x;
			int _y;
	};

	public:
		LineImpl(int x1, int y1, int x2 , int y2)
		: _p1(x1 , y1)
		, _p2(x2 , y2)
		{
			cout << "LineImpl(int, int , int, int)" << endl;
		}
		
		void disp() const
		{
			_p1.print();
			cout << "-->";
			_p2.print();
			cout << endl;
		}

		

	private:

		Point _p1;
		Point _p2;
};


Line::Line(int x1, int y1, int x2, int y2)
: _pImpl(new LineImpl(x1, y1,x2, y2))
{
	cout << "Line(int, int, int, int)" << endl;
}

Line::~Line()
{
	cout << "~Line()" << endl;
	if(_pImpl)
	{
		delete _pImpl;
	}
}

