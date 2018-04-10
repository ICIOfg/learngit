 ///
 /// @file    namespace4.cc
 /// @author  ICIOfg
 /// @date    2018-04-10 23:32:38
 ///
 

//c++为了兼容c，认为c的标准库函数统统位于匿名的名称空间
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

void fun(void)
{
	cout << "fun()" << endl;
}

int main(void)
{
	::printf("hello\n");
	::fun();
	return 0;
}
