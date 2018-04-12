 ///
 /// @file    Tarea.cc
 /// @author  ICIOfg
 /// @date    2018-04-11 23:33:42
 ///
#include <string.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class String
{
	public:
		String()
		: _pstr(new char[1]())
//		: _pstr(NULL)	
		{
			cout << "String()" << endl;
		}
		String(const char *pstr)
		:_pstr(new char[strlen(pstr)+1]())
		{
			cout << "String(const char*pstr)" << endl;
			strcpy(_pstr, pstr);
		}
		String(const String &rhs)
		:_pstr(new char[strlen(rhs._pstr)+1]())
		{
			cout << "String(const String & rhs)" << endl;
			strcpy(_pstr, rhs._pstr);
		}

		String & operator = (const String & rhs)
		{
			cout << "String & operator = (const String & rhs)" << endl;
			if(this != &rhs)
			{
				delete []_pstr;
				_pstr = new char[strlen(rhs._pstr)+1]();
				strcpy(_pstr, rhs._pstr);
			}
			return (*this);
		}

		~String()
		{
			cout << "~String()" << endl;
			if(_pstr!= NULL)
			{
				delete []_pstr;
				_pstr = NULL;
			}
		}

		void print();

	private:
		char * _pstr;
};

void String::print()
{
	cout << "_pstr=" << _pstr <<endl;
}



int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello , World";
	String str3("Wangdao");

	str2.print();
	str3.print();

	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}

