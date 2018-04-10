 ///
 /// @file    refe.cpp
 /// @author  ICIOfg
 /// @date    2018-04-10 13:55:58
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	int a = 10;
	int &ref = a;
	cout << "a =" << a << endl;
	cout << "ref = " << ref << endl;
	
	cout << "change 1" << endl;

	ref = 20;
	cout << "a =" << a << endl;
	cout << "ref = " << ref << endl;

	cout << "change 2" << endl;
	int b = 30;

	ref = b;
	cout << "a =" << a << endl;
	cout << "ref = " << ref << endl;
	cout << "b =" << b << endl;

	cout << "change 3" << endl;

	ref = 40;
	cout << "a =" << a << endl;
	cout << "ref = " << ref << endl;
	cout << "b =" << b << endl;

	return 0;
}

