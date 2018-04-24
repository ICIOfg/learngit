 ///
 /// @file    chan.cc
 /// @author  ICIOfg
 /// @date    2018-04-18 10:49:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class anotherPoint
{
	public:
		anotherPoint(double x=1, double y =1)
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

	private:

		double _ax;
		double _ay;
};




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
		Point(anotherPoint aP)
		: _x(aP._ax)
		, _y(aP._ay)
		{
			cout << "Point(anotherPoint )" << endl;
		}


		~Point()
		{
			cout << "~Point()" << endl;
		}

		void print()
		{
			cout << "(" << _x << "," << _y << ")" << endl;

		}

	
	private:
		int _x;
		int _y;

};


int main(void)
{
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
	return 0;
}




