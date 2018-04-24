 ///
 /// @file    Queue.cc
 /// @author  ICIOfg
 /// @date    2018-04-21 10:28:31
 ///
 
#include "Queue.h"
#include <iostream>
using std::cout;
using std::endl;

template<typename T, size_t m_size>
Queue<T, m_size>::Queue()
: _front(0)
, _back(0)
, _base(new T[m_size]())
{
	cout << "Queue()" << endl;
}

template<typename T, size_t m_size>
Queue<T, m_size> ::~Queue()
{
	cout << "~Queue()" << endl;
	delete []_base;
}

template<typename T, size_t m_size>
bool Queue<T, m_size> :: empty()
{
	return _back==_front;
}

template<typename T, size_t m_size>
bool Queue<T, m_size>::full()
{
	return _front==(_back+1)%m_size;
}

template < typename T, size_t m_size>
void Queue<T, m_size>::push(const T & rhs)
{
	if(!full())
	{
		_base[_back]= rhs;
		_back=++_back%m_size;
		cout << rhs <<"pushed into the queue" << endl;
	}
	else{
		cout << "the queue is full" << endl;
	}
}

template<typename T, size_t m_size>
void Queue<T,m_size>::pop()
{
	if(!empty())
	{
		_front=++_front% m_size;
	}
	else
	{
		cout << "the queue is empty" << endl;
	}
}
template <typename T, size_t m_size>
T Queue<T,m_size>::front()
{
	return _base[_front];
}

template<typename T,size_t m_size>
T Queue<T ,m_size>::back()
{
	return _base[(_back-1+m_size)%m_size];
}

template<typename T,size_t m_size>
template<typename Arg>
void Queue<T, m_size>::display(const Arg & arg)
{
	cout << "arg=" << arg<< endl;
}


