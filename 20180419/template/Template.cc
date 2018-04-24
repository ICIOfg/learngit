 ///
 /// @file    Tempate.cc
 /// @author  ICIOfg
 /// @date    2018-04-19 21:11:40
 ///
#include <string>
#include <iostream>
using std::cout;
using std::endl;
         //返回类型     //添加类型
template <typename T,int num>
T add(const T &a, const T & b)
{
	return a+b+num;
}


int main(void)
{

	cout << add<int,10>(1,2) << endl;
	cout << add<double,7>(3.3, 3.3) << endl;

	char x='a', y = 4;
	cout << add<char,3>(x,y) << endl;

	//cout << add("good", "luck") << endl;
	return 0;
}
