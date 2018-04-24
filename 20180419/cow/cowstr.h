 ///
 /// @file    cowstr.cc
 /// @author  ICIOfg
 /// @date    2018-04-19 13:46:44
 ///
#ifndef __COWSTR_H__
#define __COWSTR_H__
#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class String
{
	class Charp
	{
		public:
			Charp(size_t idx, String & self)
			: _idx(idx)
			, _self(self)
			{
			}

			operator char()
			{
				return _self._pstr[_idx];
			}

			char & operator = (const char & ch);
		private:
			size_t _idx;
			String & _self;
	};




public:
	String();
	String(const char *);
	String(const String & rhs);
	String & operator=( const String & rhs);

	~String();
	const char * c_str() const
	{
		return _pstr;
	}
	size_t size()
	{
		return strlen(_pstr);
	}

	size_t refCount() const
	{
		return    ((int*)(_pstr - 4))[0];
	}
	
	const char & operator [](size_t idx) const
	{
		return _pstr[idx];
	}

	Charp operator[](size_t idx);



friend std::ostream &operator << (std::ostream &os, const String & rhs);
private:
	void initRefCount()
	{
		( (int*)(_pstr-4))[0]=1;
	}

	void increaseRefCount()
	{
		++*((int*)(_pstr -4));
	}

	void decreaseRefCount()
	{
		--*((int*)(_pstr -4));
	}

	void release()
	{
		decreaseRefCount();
		if(refCount()==0)
		{
			delete [](_pstr-4);
			cout << "release data" << endl;
		}
	}
		

	char * _pstr;
};

#endif
//std::ostream &operator << (std::ostream &os, const String & rhs)
//{
//	os << rhs._pstr ;
//	return os;
//}


