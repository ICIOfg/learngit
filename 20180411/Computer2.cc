 ///
 /// @file    Computer.cc
 /// @author  ICIOfg
 /// @date    2018-04-11 21:55:26
 ///
#include <string>
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Computer
{//类的默认访问权限是private，在public之前，只能内部访问，体现封装性
private:

	char m_brand[32];
	float m_price;

public://称为类对外部提供的服务或接口， 在类内部实现的函数都是inline接口
	void setBrand(const char *brand);

	void setPrice( float price);
	void print()
	{
		cout << "m_brand=" << m_brand <<endl;
		cout << "m_price=" << m_price <<endl;
	}

};
//类明具有作用域效果
void Computer :: setBrand(const char * brand)
{
	::strcpy(m_brand, brand);
}

void Computer :: setPrice(float price)
{
	m_price= price;
}




struct Person 
{//类和struct类似，但是struct默认访问权限是public
	void setName(const string & name)
	{
		_name = name;
	}

	void setGender(bool gender)
	{
		_gender = gender;
	}

	void print()
	{
		cout << "姓名："<< _name << endl
			<< "性别：" << _gender << endl;
	}

	string _name;
	bool _gender;
};





int main(void)
{
	Computer com1;
	//com1.m_price= 6000;  //private and protected 不可以在类之外访问

	com1.setBrand("acer");//public 可以在类之外访问
	com1.setPrice(3200);

	com1.print();

	Person person;
	person._name= "Mike";
	person._gender= true;
	person.print();

	person.setName("huahua");
	person.setGender(false);
	person.print();



	return 0;
}


