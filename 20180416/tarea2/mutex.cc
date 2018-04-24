 ///
 /// @file    mutex.cc
 /// @author  ICIOfg
 /// @date    2018-04-16 21:40:39
 ///
 
#include "mutex.h"
#include <iostream>
using std::cout;
using std::endl;

Mutex::Mutex()
{
	pthread_mutex_init(&_mutex, NULL);
}

Mutex::~Mutex()
{
	pthread_mutex_destroy(&_mutex);
}
void Mutex::lock()
{
	pthread_mutex_lock(&_mutex);
}

void Mutex::unlock()
{
	pthread_mutex_unlock(&_mutex);
}


