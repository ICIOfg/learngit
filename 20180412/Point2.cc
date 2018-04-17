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
		int _ix;
		int _iy;
		

	public:
// const型 与 引用型 都只能在初始化列表中初始化
		Point(int x, int y )
		: _ix(x)
		, _iy(y)
	//	, _refx( refx)
		{
			cout << "Point( int , int , double &)" << endl;
		}

		void print()// const  //函数后面加const限定权限为只读
		{
		//	_ix = 6;
			cout << "(" << _ix
				<< "," << _iy
				//<< "," << _refx
				<< ")" << endl;
		}
		void print() const  //函数后面加const限定权限为只读
		{
		//	_ix = 6;
			cout << "(" << _ix
				<< "," << _iy
				//<< "," << _refx
				<< ")" << endl;
		}

};

int main(void)
{
	//double refx = 3.3;
const	Point p1( 2, 2) ;
	p1.print();  //const 对象只能调用const成员函数

	Point p2(3, 3);
	p2.print();  //非const对象 既能调用const成员函数，也可以调用
									//非const成员函数


//	refx = 6.6;
//	p1.print();

	return 0;
}

	





	




