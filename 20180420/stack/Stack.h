 ///
 /// @file    Stack.h
 /// @author  ICIOfg
 /// @date    2018-04-20 20:06:54
 //
 
#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>
#include <string>
using std::cout;
using std::endl;

template <typename Type, size_t m_size = 10>
class Stack
{
	public:
		Stack()
		:_top(-1)
		,_base(new Type[m_size]())
		{
			cout << "Stack()" << endl;
		}
		~Stack();
		bool empty()const;
		bool full()const;
		void push(const Type & rhs);
		void pop();
		Type top();

		template <typename Arg>      //类模板中嵌套一个成员函数模板
		void display(const Arg & rhs);
	private:
		int _top;        //栈顶
		Type * _base;	//栈元素，类型可变
};

#endif
