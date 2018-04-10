 ///
 /// @file    getvalue.cc
 /// @author  ICIOfg
 /// @date    2018-04-10 15:31:01
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int & getvalue()
{
	int a=10;
	return a;
}



int main(void)
{

//	int b=20;
	int & ref = getvalue();
	cout << "ref =" << ref << endl;
	return 0;
}

