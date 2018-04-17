 ///
 /// @file    Point.cc
 /// @author  ICIOfg
 /// @date    2018-04-12 21:48:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	int _ix;
	int _iy;

	public:
//无参构造函数
		Point()
		: _ix(0)
		, _iy(0)
		{
			cout << "Point()" << endl;
		}
//缺省参数构造函数, 双无参会与无参函数冲突， 双有参会与有参函数冲突
//注意避免冲突
#if 0
		Point(int x, int y = 0)
		: _ix(x)
		, _iy(y)
		{
			cout << "Point(0 , 0)" << endl;
		}
#endif
//有参构造函数
		Point( int x, int y)
		: _ix(x)
		, _iy(y)
		{
			cout << "Point(int , int)" << endl;
		}
//复制构造函数
		Point(const Point & rhs)
		: _ix(rhs._ix)
		, _iy(rhs._iy)
		{
			cout << "Point(const Point & rhs)" << endl;
		}
//赋值运算函数
//如果没有显示提供，编译器会自动提供
//目前，除了static函数，每个函数第一个参数都为this指针（隐式），
//this指针代表当前对象     Point * const this
		Point & operator = (const Point & rhs)
		{
			cout << "Point & operator = (const Point & rhs)" << endl;
			this->_ix = rhs._ix;
			this->_iy = rhs._iy;
			return *this;
		}

		void print(/* Point * const this */)
		{

			cout << "(" << this->_ix
				<< "," << this->_iy
				<<")" << endl;
		}

		~Point()  //清理工作
		{
			cout << "~Point " << endl;
		}
};


int main(void)
{
	int a = 5;
	int b = a;
	cout << "a=" << a
		<<"b=" << b << endl;


	Point p1;
	cout << "p1=";
	p1.print();

	Point p2(1,1);
	cout << "p2=";
	p2.print();

	Point p3(2,2);
	cout << "p3=";
	p3.print();
//复制创建时就照着复制
	Point p4 = p3;
	cout << "p4=";
	p4.print();
//赋值，先创建用构造函数，再各成员赋值
	Point p5;
	p5 = p2;
	cout << "p5=";
	p5.print();


	return 0;
}

