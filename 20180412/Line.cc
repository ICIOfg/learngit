 ///
 /// @file    Line.cc
 /// @author  ICIOfg
 /// @date    2018-04-12 10:38:06
 ///
 
#include <iostream>
using namespace std;

class Point
{
	private:
		int m_Xpo;
		int m_Ypo;
	public:
		Point(int x=0, int y =0)
		: m_Xpo(x)
		, m_Ypo(y)
		{
			cout << "Point 缺省调用构建函数" << endl;
			//m_Xpo=x;
			//m_Ypo = y;
		}
		Point(const Point & rhs)
		: m_Xpo(rhs.m_Xpo)
		, m_Ypo(rhs.m_Ypo)
		{
			cout << "Point 复制构造函数" << endl;
			//m_Xpo = rhs.m_Xpo;
			//m_Ypo = rhs.m_Ypo;
		}
		void print()
		{
			cout << "(" << m_Xpo << "," << m_Ypo << ")" << endl;
		}

};


class Line
{
	Point pt1;
	Point pt2;

	public:

	Line(int x1, int y1, int x2, int y2)
	: pt1(x1, y1)
	, pt2(x2, y2)
	{
		cout << "Line 有参构造函数 " << endl;
	}

	Line(const Line & lp)
	: pt1(lp.pt1)
	, pt2(lp.pt2)
	{
		cout << "Line 复制构造函数" << endl;
	}
	void draw()
	{
		pt1.print();
		cout << "to" ;
		pt2.print();
		cout << endl;
	}
};


int main(void)
{
	Line lp1(2, 2, 3, 3);
	lp1.draw();

	Line lp2(lp1);
	lp2.draw();

	return 0;
}

