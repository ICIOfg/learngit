 ///
 /// @file    const.c
 /// @author  ICIOfg
 /// @date    2018-04-10 15:52:14
 ///
 
#include <iostream>
using std::cout;
using std::endl;



int main(void)
{
	int a = 10;
	int b = 20;

	int const *p = &a;
	p=&b;
//	*p = 100;//erro，常量指针不能改变值，但可以改变指向
//	同 const int *p;
	
	const int *p1=&a;
	p1 = &b;
//	*p1 =100;

	int * const p2 = &a;
//	p2 = &b;  //指针常量不能改变指向， 但可以改变值
	*p2 = 100;
	
	return 0;
}


