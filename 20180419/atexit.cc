 ///
 /// @file    atexit.cc
 /// @author  ICIOfg
 /// @date    2018-04-19 13:41:09
 ///
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

void test(void)
{
	cout << "test()" << endl;
}

int main(void)
{
	cout << "start.." << endl;
//进程退出后会自动调用已经注册的函数，
//一个函数可以注册多次
//注册几次就执行几次
	::atexit(test);
	::atexit(test);
	::atexit(test);

	cout << "end" << endl;
	return 0;
}
