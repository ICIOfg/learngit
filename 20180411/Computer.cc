 ///
 /// @file    Computer.cc
 /// @author  ICIOfg
 /// @date    2018-04-11 21:55:26
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;

class Computer
{//类的默认访问权限是private，在public之前，只能内部访问，体现封装性
	char m_brand[32];
	float m_price;

public://称为类对外部提供的服务或接口， 在类内部实现的函数都是inline接口
	void setBrand(const char *brand)
	{
		::strcpy(m_brand, brand);
	}

	void setPrice( float price)
	{
		m_price = price;
	}
	void print()
	{
		cout << "m_brand=" << m_brand <<endl;
		cout << "m_price=" << m_price <<endl;
	}

};


int main(void)
{
	Computer com1;
	//com1.m_price= 6000;  //private and protected 不可以在类之外访问

	com1.setBrand("acer");//public 可以在类之外访问
	com1.setPrice(3200);

	com1.print();
	return 0;
}


