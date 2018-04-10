 ///
 /// @file    extern.cc
 /// @author  ICIOfg
 /// @date    2018-04-10 22:15:15
 ///
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;


//实现c与c++的混合编程
#ifdef __cplusplus
extern "C"//在其内部的函数都会按照c的方式进行调用，不会进行名字改编
{
#endif
int add(int x, int y)
{
	return x + y;
}

#ifdef __cplusplus
}
#endif
int add( int x, double y)
{
	return x +y;
}

int add(int x, int y, int z)
{
	return x + y + z;
}

int main(void)
{
	int a=3, b= 4, c = 5;

	double d= 2.5;

	cout << "add(a,b)=" << add(a,b) << endl;
	cout << "add(a,d)=" << add(a,d) <<endl;
	cout << "add(a,b,c)=" << add(a, b ,c) << endl;

	return 0;
}

