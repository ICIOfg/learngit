 ///
 /// @file    cond.h
 /// @author  ICIOfg
 /// @date    2018-04-16 21:52:20
 ///
#ifndef __COND_H__
#define __COND_H__
#include <iostream>
#include <pthread.h>

using std::cout;
using std::endl;
class Mutex; //类的前向声明，减少头文件的依赖

class Cond
{
	public:
		Cond(Mutex & mutex);
		~Cond();

		void wait();
		void notify();
		void notifyall();
//
//
//禁止复制
		Cond(const Cond &) = delete;
		Cond & operator = (const Cond &) = delete;


	private:
		
		pthread_cond_t _cond;
		Mutex & _mutex;
};

#endif
