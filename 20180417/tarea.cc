 ///
 /// @file    tarea.cc
 /// @author  ICIOfg
 /// @date    2018-04-17 20:23:28
 ///
 
#include <iostream>
#include <string.h>
#include <string>
using std::cout;
using std::endl;
using std::cin;
class String
{
	public:
		String()
		:_pstr(NULL)
		{
			cout << "String()" <<endl;
		}

		String(const char* rhs)
		:_pstr(new char[strlen(rhs)+1]())
		{
			cout << "String(const char*)" << endl;
			strcpy(_pstr, rhs);
		}
		String(const String & rhs)
		:_pstr(new char[strlen(rhs._pstr)+1]())
		{
			cout << "String(const String & rhs)" << endl;
			strcpy(_pstr, rhs._pstr);
		}
		~String()
		{
			cout << "~String()" << endl;
			delete []_pstr;
		}
		String & operator = (const String &rhs)
	//	:_pstr(new char[strlen(rhs._pstr)+1]())  //不是构造函数，不能用初始化
		{
			_pstr=(new char[strlen(rhs._pstr)+1]());  
			cout << "String & operator = (const String & )" << endl;
			strcpy(_pstr, rhs._pstr);
			return (*this);
		}


		String & operator = (const char *rhs)
		{
			_pstr=(new char[strlen(rhs)+1]());
			cout << "String & operator = (const char * )" << endl;
			strcpy(_pstr, rhs);
			return (*this);
		}


		String & operator += (const String & rhs)
		{	
			cout << "String & operator += (const char & )" << endl;
			char *p = new char[strlen(_pstr)+strlen(rhs._pstr)+1]();
			strcpy(p, _pstr);
			strcat(p, rhs._pstr);
			delete []_pstr;
			this->_pstr= p;
			return (*this);
		}
		String & operator += (const char *rhs)
		{	
			cout << "String & operator += (const char*  )" << endl;
			char *p= new char[strlen(_pstr)+strlen(rhs)+1]();
			strcpy(p, _pstr);
			strcat(p, rhs);
			delete []_pstr;
			this->_pstr = p;
			return (*this);
		}

		char & operator[](std::size_t index)
		{
			return _pstr[index];
		}

		const char & operator[](std::size_t index) const
		{
			return _pstr[index];
		}

		std::size_t size() const
		{
			return strlen(_pstr);
		}
		const char* c_str() const
		{
			return _pstr;
		}

		friend bool operator == (const String &, const String &);
		friend bool operator != (const String &, const String &);

		friend bool operator < (const String &, const String &);
		friend bool operator > (const String &, const String &);

		friend bool operator <= (const String &, const String &);
		friend bool operator >= (const String &, const String &);


		friend std::ostream & operator << (std::ostream & os, const String & s);
		friend std::istream & operator >> (std::istream & is, String & s);

		void disp(int rhs)
		{
			cout << "s" <<rhs <<"=" << _pstr << endl;
		}
		char* getString() const
		{
			return this->_pstr;
		}

	private:
		char * _pstr;
};

String operator + (const String & lhs, const String & rhs)
{
	char *p = new char[strlen(lhs.getString())+strlen(rhs.getString())+1]();
	strcpy(p, lhs.getString());
	strcat(p, rhs.getString());
	return String(p);
}

String operator + (const String & lhs, const char * rhs)
{
	char *p = new char[strlen(lhs.getString())+strlen(rhs)+1]();
	strcpy(p, lhs.getString());
	strcat(p, rhs);
	return String(p);
}
String operator + (const char * lhs, const String & rhs)
{
	char *p = new char[strlen(lhs)+strlen(rhs.getString())+1]();
	strcpy(p, lhs);
	strcat(p, rhs.getString());
	return String(p);
}

//函数实现

bool operator == (const String & lhs, const String & rhs)
{
	if(!strcmp(lhs._pstr, rhs._pstr))
	{
		return true;
	}
	else{
		return false;
	}
}
	
	
 bool operator != (const String & lhs,const String & rhs)
{
	if(!strcmp(lhs._pstr, rhs._pstr))
	{
		return false;
	}
	else{
		return true;
	}
}

bool operator < (const String & lhs, const String & rhs)
{
	if(strcmp(lhs._pstr, rhs._pstr)< 0)
	{
		return true;
	}
	else{
		return false;
	}
}

bool operator > (const String & lhs, const String & rhs)
{
	if(strcmp(lhs._pstr, rhs._pstr)> 0)
	{
		return true;
	}
	else{
		return false;
	}

}

bool operator <= (const String & lhs, const String & rhs)
	{
		if(strcmp(lhs._pstr, rhs._pstr)> 0)
		{
			return false;
		}
		else{
			return true;
		}
	}

bool operator >= (const String & lhs, const String & rhs)
{
	if(strcmp(lhs._pstr, rhs._pstr)< 0)
	{
		return false;
	}
	else{
		return true;
	}
}
	
std::ostream & operator << (std::ostream & os, const String & s)
{
	os << s._pstr << endl;
}



std::istream & operator >> (std::istream & is, String & s)
{
	s._pstr=new char[512];
	is >> s._pstr;
	return is;
}










int main(void)
{//增量编写

	String s1;
//	s1.disp();
	String s2("hello");
	s2.disp(2);
	String s3(s2);
	s3.disp(3);
	
	String s4 = "world";  //等同 String s2("hello");
	s4.disp(4);

	String s5;
	s5 = "world";
	s5.disp(5);

	String s6;
	s6 = s5;
	s6.disp(6);

	String s7("hello");
	s7 += s5;
	s7.disp(7);

	String s8("hello");
	s8 += "world";
	s8.disp(8);

	String s9("abcdefghi");
	
	cout <<"s9 has --> " <<  s9[3] << endl;
	
	cout << "s9's size is:" << s9.size() << endl;
	cout << "s9 is:" << s9.c_str() << endl;
	
	cout << "s2 == s4:" << (s2 ==s4) << endl;
	cout << "s2 != s4:" << (s2 !=s4) << endl;
	cout << "s2 < s4:" << (s2 <s4) << endl;
	cout << "s2 > s4:" << (s2 >s4) << endl;
	cout << "s2 <= s4:" << (s2 <=s4) << endl;
	cout << "s2 >= s4:" << (s2 >=s4) << endl;
	
	cout << "s2 + s4" << (s2 + s4) << endl;
	cout << "s2 + worlddd" << (s2 + "worlddd") << endl;
	cout << "good + s4" << ("good" + s4) << endl;


	String s10;
	cin >> s10;
	cout << s10;


	return 0;
}



