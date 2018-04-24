 ///
 /// @file    Friend.cc
 /// @author  ICIOfg
 /// @date    2018-04-17 16:51:50
 ///
 
#include <iostream>
#include <cmath>
using std::cout;
using std::endl;


class Point 
{
	public:
		Point(int x = 0,int y = 0)
		: _x(x)
		, _y(y)
		{
			cout << "Point(int, int)" << endl;
		}

		~Point()
		{
			cout <<"~Point()" << endl;
		}
//友元函数的声明跟位置没有关系，可以在public，也可以在private	
	friend float dis(Point & lhs, Point & rhs);


	
	private:
		int _x;
		int _y;

};
//将外部函数声明为友元函数，可以通过友元函数外部调用类成员

float dis(Point & lhs, Point & rhs)
{
	return sqrt((lhs._x-rhs._x)*(lhs._x-rhs._x)+(lhs._y - rhs._y)*( lhs._y - rhs._y));
}

int main(void)
{
	Point p1(1,1);
	Point p2(4, 5);
	float m = dis(p1, p2);
	cout << "distance between points is:" << m << endl;
	return 0;
}
