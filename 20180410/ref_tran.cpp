 ///
 /// @file    ref_tran.cpp
 /// @author  ICIOfg
 /// @date    2018-04-10 14:02:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void swap(int &x, int &y)
{
	int tem = x;
	x = y;
	y = tem;
}




int main(void)
{
	int a = 5;
	int b = 6;
	cout << "a =" << a << endl;
	cout << "b =" << b << endl;
	cout << "after change" << endl;

	swap(a, b);
	cout << "a =" << a << endl;
	cout << "b =" << b << endl;
	return 0;
}
	


