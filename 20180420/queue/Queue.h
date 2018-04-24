 ///
 /// @file    Queue.h
 /// @author  ICIOfg
 /// @date    2018-04-20 22:54:05
 ///
#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <iostream>
#include <string>
#include <string.h>
using std::cout;
using std::endl;
using std::string;

template <typename T,size_t m_sizei=8> 
class Queue
{
	public:
		Queue();
		~Queue();
		bool empty();
		bool full();
		void push(const T & rhs);
		void pop();
		T front();
		T back();
	    
		template <typename Arg>
		void display(const Arg & arg);

	private:
		int _front;
		int _back;
		T * _base;
};


#endif

	
