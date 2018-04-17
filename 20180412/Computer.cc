 ///
 /// @file    Computer.cc
 /// @author  ICIOfg
 /// @date    2018-04-12 23:33:11
 ///
#include <string.h> 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Computer
{

	char * _brand;
	float _price;
	static float _totalprice;
	public:

		Computer(const char * brand, float price)
		:_brand(new char[strlen(brand)+1]())
		, _price( price)
		{
			strcpy( _brand, brand);
			cout << "Computer(const char * brand, float price)" << endl;
			_totalprice += _price;
		}
		
		Computer ( const Computer & rhs)
		: _brand( new char[strlen(rhs._brand)+1]())
		, _price (rhs._price)
		{
			strcpy(_brand, rhs._brand);
			cout << "Computer ( const Computer & rhs)" << endl;
		}
		void print()
		{
			cout << "品牌" << _brand << endl;
			cout << "价格" << _price << endl;
		}




		Computer & operator = ( const Computer & rhs)
		{
			if(this!= &rhs)//自复制
			{
				delete []_brand;//回收左函数开辟的空间
				_brand = new char[strlen(rhs._brand)+1]();
				strcpy(_brand, rhs._brand);//深拷贝
				_price = rhs._price;
			}
			return *this;
			cout << "Computer & operator ( const Computer & rhs)" << endl;
		}

		static void printTotalPrice()
		{
			cout << "总价" << _totalprice << endl;
		}

		~Computer()
		{
			delete [] _brand;
			cout << "~Computer" << endl;
		}

		void setBrand(const char * brand);

		void setPrice( float price);

};

void Computer::setBrand( const char * brand)
{
	strcpy( _brand, brand);
}

void Computer::setPrice( float price)
{
	_price = price;
}


float Computer::_totalprice = 0.0;

int main(void)
{
	Computer::printTotalPrice();//不需要产生对象就可以调用静态成员函数

	Computer com1("acer", 3500);
	cout << "com1";
	com1.print();
	com1.printTotalPrice();

	Computer::printTotalPrice();//静态成员函数可以通过类名进行调用

	return 0;
}

			

