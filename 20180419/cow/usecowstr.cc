 ///
 /// @file    usecowstr.cc
 /// @author  ICIOfg
 /// @date    2018-04-19 17:17:28
 ///
#include "cowstr.h" 

int main(void)
{

	String s1= "hello";
	String s2= "world";
	String s3 = s1;

	cout << "s1=" << s1 << endl;
	cout << "s2=" << s2 << endl;

	cout << "s3=" << s3 << endl;

	printf("s1' addr is %p\n",s1.c_str());
	printf("s2' addr is %p\n",s2.c_str());
	printf("s3' addr is %p\n",s3.c_str());

	s1[0]='w';
	cout << "s1第一个字母换为w"<< endl;
	cout << "s1=" << s1 << endl;
	printf("s1' addr id %p\n", s1.c_str());

	cout << "读取s3[0]" << s3[0] << endl;
	printf("s3' addr id %p\n", s3.c_str());


	return 0;
}
