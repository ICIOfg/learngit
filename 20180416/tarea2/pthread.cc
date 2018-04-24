 ///
 /// @file    pthread.cc
 /// @author  ICIOfg
 /// @date    2018-04-16 23:12:51
 ///

#include "mutex.h"
#include "cond.h"
#include <unistd.h>
#include <iostream>
using std::cout;
using std::endl;

Mutex mutex;

Cond cond(mutex);

int count = 0;
int flag = true;

void * func1(void * arg)
{
	int number = 10;
	while(number--)
	{

		mutex.lock();
		if(flag)
		{
			cond.wait();
		}

		++count;
		cout << ">" << pthread_self() << "count =" << count << endl;

		if(flag == false)
		{
			flag = true;
			cond.notify();
		}

		mutex.unlock();
	}
	return NULL;
}


void * func2( void * arg)
{

	int number = 10;
	while(number--)
	{

		mutex.lock();
		if(!flag)
		{
			cond.wait();
		}

		++count;
		cout << ">" << pthread_self() << "count =" << count << endl;

		if(flag )
		{
			flag = false;
			cond.notify();
		}

		mutex.unlock();
	}
	return NULL;
}

int main(void)
{
	pthread_t pth1, pth2;
	pthread_create(&pth1,NULL, func1, NULL);
	pthread_create(&pth2,NULL, func2, NULL);

	pthread_join(pth1,NULL);
	pthread_join(pth2, NULL);

	return 0;
}



