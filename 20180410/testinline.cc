 ///
 /// @file    testinline.cc
 /// @author  ICIOfg
 /// @date    2018-04-10 20:52:01
 ///
 
#include "inline.h"
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	int a = 3, b = 4;

	cout << "a * b=" << func(a,b) << endl;

	cout << "Max(a,b)=" << Max(a,b) << endl;

	cout << "get(a,b)=" << getvalue(a, b) << endl;

	return 0;

}
