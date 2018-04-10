 ///
 /// @file    overload.cc
 /// @author  ICIOfg
 /// @date    2018-04-10 21:08:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//c++语言支持函数重载，c语言不支持
//
//实现原理：名字改编（name mangling）
//g++ -c *.cc
//nm *.o
//
//
//
//具体步骤：当函数名相同时，会根据参数的个数，类型，顺序不同进行改编

int add(int x, int y)
{
	return x + y;
}

int add(int x, int y, int z)
{
	return x +y + z;
}

double  add(int x, double y)
{
	return x * y;
}

double add(double x, int y)
{
	return x/y;
}



int main(void)
{
	int a =3;
	int b = 4;
	int c = 5;
	double d = 6.6;

	cout << "a + b =" << add(a, b) << endl;
	cout << " a + b+ c= " << add(a, b, c) << endl;
	cout << " a * d= " << add( a, d) << endl;
	cout << " d/a= " << add( d, a) << endl;

	return 0;
}
