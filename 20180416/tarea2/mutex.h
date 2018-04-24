 ///
 /// @file    mutex.h
 /// @author  ICIOfg
 /// @date    2018-04-16 21:31:13
 ///

#ifndef __MUTEX_H__
#define __MUTEX_H__


#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;

class Mutex
{
	public:
		Mutex();
		~Mutex();
		void lock();
		void unlock();

		pthread_mutex_t * getmutexptr()
		{
			return &_mutex;
		}
//	private:  
		//禁止 复制              //C++11用法
		Mutex(const Mutex &)=delete;

		Mutex & operator = (const Mutex &) = delete;


	private:

		pthread_mutex_t _mutex;
};

class MutexGuard
{
	public:
		MutexGuard(Mutex & mutex)
		:_mutex(mutex)
		{
			_mutex.lock();
		}


		~MutexGuard()
		{
			_mutex.unlock();
		}
	private:
		Mutex & _mutex;
};



#endif
