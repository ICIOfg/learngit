 ///
 /// @file    cond.cc
 /// @author  ICIOfg
 /// @date    2018-04-16 21:56:09
 ///
#include "cond.h" 
#include "mutex.h"
#include <iostream>
using std::cout;
using std::endl;


Cond::Cond(Mutex & mutex)
:_mutex(mutex)
{

	pthread_cond_init(&_cond, NULL);
}

Cond::~Cond()
{
	pthread_cond_destroy(&_cond);
}

void Cond::wait()
{
	pthread_cond_wait(&_cond, _mutex.getmutexptr());

}

void Cond::notify()
{
	pthread_cond_signal(&_cond);
}

void Cond::notifyall()
{
	pthread_cond_broadcast(&_cond);
}



