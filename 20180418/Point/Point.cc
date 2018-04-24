 ///
 /// @file    Point.cc
 /// @author  ICIOfg
 /// @date    2018-04-18 19:46:20
 ///
#include "log.h" 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
		Point( int x = 0, int y = 0 )
		: _ix(x)
		, _iy(y)  
		{
			cout << "Point()" << endl;
			LogDebug("Point(int, int)");
		}

		void print()
		{
		//	LogInfo();
			cout << "(" << _ix << "," << _iy << ")" << endl;
		}


		~Point()
		{
			cout << "~Point()" << endl;
		}


	private:
		int _ix;
		int _iy;

};

int main(void)
{

	Point p1 = 5;//由其他类型转换成自定义-->由构造函数完成
	p1.print();
	return 0;

}





