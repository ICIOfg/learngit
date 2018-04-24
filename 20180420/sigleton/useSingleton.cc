 ///
 /// @file    useSingleton.cc
 /// @author  ICIOfg
 /// @date    2018-04-21 15:45:30
 ///
 
#include <iostream>
#include "Singleton.h"
//#include "Singleton.cc"
using std::cout;
using std::endl;



int main(void)
{
	Computer * p1 = Singleton<Computer>::getInstance("Xiaomi",6666);
	Computer * p2 = Singleton<Computer>::getInstance("Xiaomi",6666);
	cout <<"p1:"<< p1 <<  endl;
	cout <<"p2:"<< p1<< endl;

	Point * p3 = Singleton<Point>::getInstance(1,2);
	Point * p4 = Singleton<Point>::getInstance(1,2);

	return 0;
}
