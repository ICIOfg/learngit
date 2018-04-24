 ///
 /// @file    Complex.cc
 /// @author  ICIOfg
 /// @date    2018-04-17 17:43:51
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Complex
{
	public:
		Complex(double x = 0.0, double y = 0.0)
		:_real(x)
		,_img(y)
		{
			cout << "Complex(double , double)" << endl;
		}

		void disp()
		{
			cout << _real << "+" << _img << "*i" << endl;
		}
		double getReal() const
		{
			return _real;
		}

		double getImg() const
		{
			return _img;
		}
//成员函数形式重载运算符
	Complex operator+=(const Complex & rhs)
	{
		cout << "operator+=" << endl;
		_real += rhs._real;
		_img += rhs._img;
		return (*this);
	}
	
	Complex operator +(const Complex & rhs)
	{
		cout << "operator+" << endl;
		return Complex(_real + rhs._real, _img + rhs._img);
	}


//友元函数形式重载运算符
//	friend	Complex  operator +(const Complex & lhs, const Complex & rhs);

	private:
		double _real;
		double _img;
};

//friend
#if 0
		Complex  operator +(const Complex & lhs, const Complex & rhs)
		{
			return Complex(lhs._real + rhs._real, lhs._img + rhs._img);
		}
#endif
//普通函数
#if 0
		Complex  operator + (const Complex & lhs, const Complex & rhs)
		{
			cout << "operator +" << endl;
			return Complex(lhs.getReal()+rhs.getReal(), lhs.getImg()+ rhs.getImg());
		}
#endif

int main(void)
{
	Complex c1(3 , 4);
	c1.disp();
	Complex c2(2 , 1);
	c2.disp();
//	Complex c3 = operator+( c1 , c2);  //不能直接加法运算
//	c3.disp();

//普通函数
#if 0
	Complex c4 = c1 + c2;                   //普通表达式
	c4.disp();
	Complex c5 = operator+(c1, c2);			//等价的函数表达式
	c5.disp();
#endif
	
	Complex c3;
	c3.disp();
	c3.operator+=(c1);
	
	c3.disp();


	return 0;
}

