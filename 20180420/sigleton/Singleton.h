 ///
 /// @file    Sigleton.h
 /// @author  ICIOfg
 /// @date    2018-04-21 15:20:31
 ///
#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <iostream>
#include <string.h>
#include <stdio.h>
using std::cout;
using std::endl;


class Point
{
	public:
		Point(int x=0, int y=0)
		: _ix(x)
		, _iy(y)
		{
			cout << "Point()" << endl;
		}

		~Point()
		{
			cout << "~Point()" << endl;
		}

	private:
		int _ix;
		int _iy;
};

class Computer
{
	public:
		Computer(const char * brand, double price)
		: _brand(new char[strlen(brand)+1]())
		, _price(price)
		{
			strcpy(_brand, brand);

			cout << "Computer()" << endl;
		}

		~Computer()
		{
			cout << "~Computer()" << endl;
		}



	private:
		char * _brand;
		double _price;
};


//先写单例模式
//单例，成员对象空间在堆内存，且为一个
template<typename T>
class Singleton
{
	class autoDes
	{
		public:
			autoDes()
			{
				cout << "autoDes()" << endl;
			}
			~autoDes()
			{
				if(_pInstance)
				{
					delete _pInstance;
					cout << "~autoDes()" << endl;
				}
			}
	};

	public:
		template<typename t1, typename t2>
		static T * getInstance(const t1  lhs,const t2  rhs);
#if 0	
		{
			if(_pInstance==NULL)
			{
				_pInstance=new T;
			}
			return _pInstance;
		}
#endif
		void destroy()
		{
			if(_pInstance!=NULL)
			{
				
				delete []_pInstance;
			}
		}

	private:
		Singleton(){ cout << "Sigleton()" << endl;}
		~Singleton(){cout << "~Sigleton()"<< endl;}

		static	T * _pInstance;
		static autoDes _auto;
};
template <typename T>
T * Singleton<T>::_pInstance = NULL;

template<typename T>
typename Singleton<T>::autoDes Singleton<T>::_auto;



template <typename T>
template<typename t1, typename t2>
T * Singleton<T>::getInstance(const t1  lhs, const t2  rhs)
{
	if(_pInstance==NULL)
	{
		_auto;
		_pInstance = new T(lhs, rhs);
	}
	return _pInstance;
}




#endif


