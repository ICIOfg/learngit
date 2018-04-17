 ///
 /// @file    Stack.cc
 /// @author  ICIOfg
 /// @date    2018-04-12 17:45:17
 ///
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Stack
{
	private:
		int _sumTop;
		int _sta[10];
		int _max;
	public:
		Stack()
		:_sumTop(-1)
		,_max(10)
		{

			cout << "Stack()" <<endl;

		}
		void push(int x)
		{
//			cout << full() << endl;
			if(!full())
			{
				++_sumTop;
				_sta[_sumTop] = x;
				cout << "push(int x):"<< x << endl;
				return ;
			}
			cout << "full,false push" << endl;
			exit(1);
		}

		void pop()
		{
			if( empty())
			{
				cout << "pop:" << _sta[_sumTop] <<endl;
				--_sumTop;
				return;
			}
			cout << "empty" <<endl;
			exit(1);
		}


		bool full()
		{
//			cout << "_sumTop" << _sumTop <<endl;
//			cout << _max << endl;
			if(_sumTop == _max)
			{
				return 1;
			}
			return 0;
		}

		bool empty()
		{
			if(_sumTop == -1)
			{
				return 0;
			}
			return 1;
		}

		int top()
		{
			cout << "_sta[_sumTop]" << _sta[_sumTop] << endl;
		}
		
		

};

//Stack Stack::_sumTop = -1;
//
//

int main(void)
{
	Stack tt;
	tt.push(10);
	tt.push(12);
	tt.push(14);
	tt.top();
	tt.pop();
	tt.top();

	return 0;
}


