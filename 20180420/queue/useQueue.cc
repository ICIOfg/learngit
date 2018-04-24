 ///
 /// @file    useQueue.cc
 /// @author  ICIOfg
 /// @date    2018-04-21 11:15:54
 ///
#include "Queue.h"
#include "Queue.cc"
#include <iostream>
#include <string>
using std::cout;
using std::endl;


void testInt(void)
{
	Queue<int> qq;
	cout << "qq.empty() is:" << qq.empty() << endl;
//	qq.push(1);
//	cout << "front() is" <<qq.front()<< endl;
//	qq.push(2);

	for(int i = 0 ; i<7 ;i++)
	{
		qq.push(i);
	}
	cout << "qq.full() is:" << qq.full() << endl;
	cout << "qq.front() is:" << qq.front() << endl;
	cout << "qq.back() is:" << qq.back() << endl;
		
	qq.pop();
	cout << "qq.front() is:" << qq.front() << endl;
	cout << "qq.back() is:" << qq.back() << endl;

}

void testChar(void)
{

	Queue<char> qq;
	qq.empty();
	qq.push('a');
	cout << "front(0) is" <<qq.front()<< endl;
	qq.push('b');
	qq.pop();

}

void testString(void)
{
	Queue<string> qq;
	qq.empty();
	qq.push(string(2,'a'));
	cout << "front(0) is" <<qq.front()<< endl;
	qq.push("bb");
	qq.pop();

	int n = 99;
	qq.display(n);
}

int main(void)
{
//	testChar();
//	testString();
	testInt();
	return 0;
}
