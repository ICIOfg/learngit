 ///
 /// @file    string.cc
 /// @author  ICIOfg
 /// @date    2018-04-10 19:17:01
 ///
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main(void)
{
	string s1 = "hello";
	string s2 = "world";

	//c++中字符串合并，可以用两对象和，也可以用字符串中成员函数实现
	string s3 = s1 + s2;
//	string s4 = s4.append(s1).append(s2); 自己赋值不可以
	string s4;

	cout << "s1 =" << s1 << endl;
	cout << "s2 =" << s2 << endl;
	cout << "s3 =" << s3 << endl;
	cout << "s4 =" << s4.append(s1).append(s2) << endl;

//计算C++字符串长度，用string.size()或string.length()	

	cout << "s4.size() =" << s4.size() << endl <<"s3.size()=" << s3.size() <<endl
	     << "s4.length() =" << s4.length() << endl;
//截取字符串中的子串
	string s5 = s4.substr(5, 3);
	cout << "s5 = " << s5 << endl;
//遍历字符串
	for(size_t i = 0; i < s4.size(); ++i)
		cout << s4[i];
	cout << endl;

//字符串比较
	cout << (s1 == s2) << endl;
//	cout << s1 == s2 << endl;
	cout << (s1 != s2) << endl;
	cout << (s1 < s2) << endl;
	cout << (s1 > s2) << endl;
//	cout << (s1 - s2) << endl; 不能操作，字符串无法进行减法运算

//	cout << "strcmp(s1, s2)= " << strcmp(s1, s2) << endl; 也不能直接对c++string进行c语言的比较操作

//将c++字符串转换成c字符串
//然后可进行c语言操作字符串
//比较大小操作后返回第一个不同值的差值
	const char* p1 = s1.c_str();
	const char * p2= s2.data();
	cout << "s1 =" << s1 << endl;
	cout << "s2 =" << s2 << endl;
	cout << "strcmp(s1,s2)=" << strcmp(p1, p2) << endl;
	char a[]="wpod";
	char b[]="wood";
	cout << "strcmp(a,b)=" << strcmp(b, a) << endl;


	return 0;
}
