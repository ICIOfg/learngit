 ///
 /// @file    Queue.cc
 /// @author  ICIOfg
 /// @date    2018-04-12 20:34:11
 ///
#include <stdlib.h> 
#include <iostream>
#define MAX 7
using std::cout;
using std::endl;

class Queue
{
	int _que[MAX];
	int _front;
	int _back;

	public:

	Queue()
	: _front(0)
	, _back(0)
	{
		cout << "Queue()" << endl;
	}
		
	void push(int x)
	{
//		cout << "_front:" << _front
//			<< "_back:" << _back << endl;
		if(!full())
		{
			_que[_back] = x;
			++_back;
			cout << "push: " << x << endl;
			return;
		}
		cout << " full queue" << endl;
		exit(1);
	}

	void pop()
	{
		if(empty())
		{
			cout << "pop:" << _que[_front] << endl;
			++_front;
			return;
		}
		cout << "empty queue" << endl;
		exit(1);
	}

	int front()
	{
//		cout << "empty:" << empty() <<endl;

		if(empty())
		{
			cout << "_front:" << _que[_front] << endl;
			return 0;
		}
		cout << "empty queue" << endl;
		exit(1);
	}

	int back()
	{
		if(empty())
		{
			cout << "_back:" << _que[_back-1] << endl;
			return 0;
		}
		cout << "empty queue" << endl;
		exit(1);
	}

	bool empty()
	{
		if(_front==_back)
		{
			return 0;
		}
		return 1;
	}

	bool full()
	{
		if((_back+1)%MAX==_front)
		{
			return 1;
		}
		return 0;
	}

};

int main(void)
{
	Queue q;
	q.push(5);
	q.push(6);
	q.push(9);
	q.front();
	q.back();
	q.pop();
	q.front();
	q.back();
	cout << "0 is empty,else not is:" << q.empty()<< endl;
	cout << "1 is full, else not is:" << q.full() << endl;


	return 0;
}


