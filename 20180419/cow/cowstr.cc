 ///
 /// @file    cowstr.cc
 /// @author  ICIOfg
 /// @date    2018-04-19 13:46:44
 ///
#include "cowstr.h" 
using std::cout;
using std::endl;

#if 0
class String
{
public:
	String();
	String(const char *);
	String(const String & rhs);
	String & operator=( const String & rhs);

	~String();


friend std::ostream &operator << (std::ostream &os, const String & rhs)
private:

	char * _pstr;
}
#endif
std::ostream &operator << (std::ostream &os, const String & rhs)
{
	os << rhs._pstr ;
	return os;
}

String::String()
:_pstr(new char[5]())
{
	cout << "String()" << endl;
	_pstr = _pstr+4;
	initRefCount();
}
String::String(const char* rhs)
:_pstr(new char[strlen(rhs)+5]())
{
	cout <<" String(const char* rhs)" << endl;
	_pstr = _pstr+4;
	initRefCount();
	strcpy(_pstr, rhs);
}
String::String(const String& rhs)
:_pstr(rhs._pstr)
{
	cout <<" String(const char* rhs)" << endl;
	increaseRefCount();
	//_pstr = _pstr+4;
//	initRefCount();
//	strcpy(_pstr, rhs._pstr);
}
String::~String()
{
	release();
	cout << "~String()" << endl;

}

String & String::operator =(const String & rhs)
{
	if(this != &rhs)    //判断是否自复制
	{
		release();				//先释放左操作数开辟空间
		_pstr = rhs._pstr;
		increaseRefCount();
	}
	return *this;
}


String::Charp String::operator[](size_t idx)
{
	return Charp(idx, *this);
}

char & String::Charp::operator=(const char & ch)
{
	if(_self.refCount() >1)
	{
		_self.decreaseRefCount();

		char * ptmp = new char[_self.size()+5]();
		strcpy(ptmp+4, _self._pstr);
		_self._pstr = ptmp +4;
		_self.initRefCount();
	}
	_self._pstr[_idx]=ch;
	return _self._pstr[_idx];
}
