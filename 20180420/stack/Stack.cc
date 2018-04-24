 ///
 /// @file    Stack.cc
 /// @author  ICIOfg
 /// @date    2018-04-20 20:05:45
 //
#include "Stack.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
#if 0
template <typename Type, size_t m_size>
Stack<Type, m_size>::Stack()
: _top(-1)
, _base(new Type[m_size]())
{
	cout << "Stack()" << endl;
}
#endif

template <typename Type, size_t m_size>
Stack<Type,m_size>::~Stack()
{
	cout << "~Stack()" << endl;
	delete []_base;
}

template <typename Type, size_t m_size>
bool Stack<Type, m_size>::empty() const
{
	return _top==-1;
}

template <typename Type, size_t m_size>
bool Stack<Type,m_size> ::full()const
{
	return _top==m_size-1;
}

template <typename Type, size_t m_size>
void Stack<Type, m_size>::push(const Type & rhs)
{
	if(!full())
	{
		_base[++_top]= rhs;
	}
	else{
		cout << "stack is full" << endl;
	}
}

template <typename Type, size_t m_size>
void Stack<Type, m_size>::pop()
{
	if(!empty())
	{
		--_top;
	}
	else{
		cout << "stack is empty" << endl;
	}
}

template <typename Type, size_t m_size>
Type Stack<Type, m_size>::top()
{
	return _base[_top];
}

template <typename Type, size_t m_size>
template <typename Arg>
void Stack<Type, m_size>::display(const Arg & rhs)
{
	cout << "display() rhs=" << rhs << endl;
}

	
