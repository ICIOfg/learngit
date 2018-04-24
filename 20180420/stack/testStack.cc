 ///
 /// @file    testStack.cc
 /// @author  ICIOfg
 /// @date    2018-04-20 20:52:48
 ///
#include "Stack.h" 
#include "Stack.cc"
#include <iostream>
using std::cout;
using std::endl;


int main(void)
{
	Stack<int> stack;
	stack.empty();
	stack.push(1);
	stack.full();
	return 0;
}
