 ///
 /// @file    Tempate.cc
 /// @author  ICIOfg
 /// @date    2018-04-19 21:11:40
 ///
#include <string>
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
T add(const T &a, const T & b)
{
	return a+b;
}


int main(void)
{

	cout << add(1,2) << endl;
	cout << add(3.3, 3.3) << endl;

	char x='a', y = 4;
	cout << add(x,y) << endl;

	//cout << add("good", "luck") << endl;
	return 0;
}
