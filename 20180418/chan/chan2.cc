 ///
 /// @file    chan.cc
 /// @author  ICIOfg
 /// @date    2018-04-18 10:49:00
 ///
 
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

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
		Point()
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
//类型转换函数的特征
//1，没有返回值
//2，没有参数
//3，在函数体内必须用传值方式以return语句返回一个目标类型的变量
//
//4，尽量不使用，不符合常理
		
		operator int()
		{
			return _x;
		}
		void print()
		{
			cout << "(" << _x << "," << _y << ")" << endl;

		}
		friend std::ostream & operator<<(std::ostream os, const Point & rhs);

	
	private:
		int _x;
		int _y;

};
std::ostream & operator <<(std::ostream os, const Point & rhs)
{
	os << "(" << rhs._x << "," << rhs._y << ")" ;
	return os;
}




int main(void)
{

	Point p1(4,5);
	cout << "p1=" << p1 << endl;//会自动调用类型转换函数，将Point对象转换为int型


	return 0;
}




