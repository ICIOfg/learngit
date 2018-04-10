 ///
 /// @file    default.cc
 /// @author  ICIOfg
 /// @date    2018-04-10 21:43:57
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//c++里定义的函数可以设置默认值（缺省参数）
//
//默认参数的顺序是从右到左的
//
//但是设置默认值可能会导致二义性，谨慎使用



int add(int x=0, int y=0)
{
	return x+y;
}

int add(double  x, double y =1.0)
{
	return x+y;
}




int main(void)
{
	int a=3, b=4, c=5, d=6;
	double e=3.0;

	cout << "add()=" << add() << endl;
	cout << "add(e)=" << add(e) << endl;


	return 0;
}
