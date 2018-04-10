 ///
 /// @file    static_cast.cc
 /// @author  ICIOfg
 /// @date    2018-04-10 22:00:09
 ///
#include <stdlib.h> 
#include <iostream>
using std::cout;
using std::endl;

int test0(void)
{
	double d = 5.5;
	int a = (int)d;
	int b = int (d);
	cout << "a =" << a << endl;
	cout << "b= " << b << endl;
	return 0;
}

void test1(void)
{
	double d= 5.5;
	int a = static_cast<int>(d);
	cout << "a= " << a << endl;
	int *p = static_cast<int*>(malloc(sizeof(int)));
	*p = 10;
	free(p);
	//const_cast/dynamic_cast/reinterpret_cast
}


int main(void)
{
	test0();
	test1();
	return 0;
}


