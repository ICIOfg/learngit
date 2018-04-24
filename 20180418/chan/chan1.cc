 ///
 /// @file    chan.cc
 /// @author  ICIOfg
 /// @date    2018-04-18 10:49:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class anotherPoint;
#if 0
class anotherPoint
{
	public:
		anotherPoint(double x=1.23, double y =1.23)
		: _ax(x)
		, _ay(y)
		{
			cout << "anotherPoint" << endl;
		}
		~anotherPoint()
		{
			cout << "~anotherPoint()" << endl;
		}
		void print()
		{
			cout << "(" << _ax << "," << _ay << ")"<< endl;
		}

	friend class Point;

	friend ostream & operator << (ostream & os, const point & pt);

	operator int()
	{
		return _x;
	}
	 
	operator double()
	{
		return _x* _y;
	}
	
	operator anotherPoint()；


	private:

		double _ax;
		double _ay;
};	
#endif



class Point
{
	public:
//		explicit    //通过构造函数隐式转换，explicit强制显示转换后
//						无法转换
		Point(int x= 0 , int y = 0)
		: _x(x)
		, _y(y)
		{
			cout << "Point()" << endl;
		}
#if 0
		Point(anotherPoint aP)
		: _x(aP._ax)
		, _y(aP._ay)
		{
			cout << "Point(anotherPoint )" << endl;
		}
#endif

		~Point()
		{
			cout << "~Point()" << endl;
		}

		void print()
		{
			cout << "(" << _x << "," << _y << ")" << endl;

		}

		operator int()
		{
			return _x;
		}
	 
		operator double()
		{
			return _x* _y;
		}
		operator anotherPoint();

	private:
		int _x;
		int _y;

	friend std::ostream & operator << ( std::ostream & os, const Point & rhs);
	
};
class anotherPoint
{
	public:
//		explicit    //通过构造函数隐式转换，explicit强制显示转换后
//						无法转换
		anotherPoint(int x= 0 , int y = 0)
		: _x(x)
		, _y(y)
		{
			cout << "anotherPoint()" << endl;
		}
#if 0
		Point(anotherPoint aP)
		: _x(aP._ax)
		, _y(aP._ay)
		{
			cout << "Point(anotherPoint )" << endl;
		}
#endif

		~anotherPoint()
		{
			cout << "~anotherPoint()" << endl;
		}

		void print()
		{
			cout << "(" << _x << "," << _y << ")" << endl;

		}

		friend std::ostream & operator << ( std::ostream & os, const anotherPoint & rhs);
	private:
		int _x;
		int _y;

//	friend std::ostream & operator << ( std::ostream & os, const Point & rhs);

};
#if 0
Point::operator anotherPoint()
{
	return anotherPoint(_x, _y);
}

#endif
  std::ostream & operator << (std::ostream & os, const Point & rhs)
  {
  	os << "(" << rhs._x << "," << rhs._y << ")" ;
  	return os;
  }
Point::operator anotherPoint()
{
	return anotherPoint(_x, _y);
}



#if 0
Point::operator anotherPoint()
{
	return anotherPoint(_x, _y);
}

#endif

std::ostream & operator << (std::ostream & os, const anotherPoint & rhs)
{
	os << "(" << rhs._x << "," << rhs._y << ")" ;
	return os;
}


int main(void)
{

#if 0
	Point p1;
	p1 = 5;   //通过构造函数进行类型转换，其他类型向自定义类型转换
//将int型转换成Point型
	p1.print();
	
	p1= 5.5;  
	p1.print();
//将double型转换成Point型
//都是通过缺省构造函数实现
	anotherPoint aP= 3.3;
	aP.print();
//将Point转换成anotherPoint型
	Point p2;
	p2 = aP;   // 等价于p2=Point(aP);
	
	p2.print();
#endif

	Point p1(3,4);
	cout << "p1=" << p1 << endl;
	int m;
	m = p1;
	cout << "m=" << m << endl;
	
	double m1;
	m1= p1;
	cout << "m1=" << m1 << endl;

	anotherPoint ap = p1;
	cout << "ap=" << ap << endl;

	return 0;
}




