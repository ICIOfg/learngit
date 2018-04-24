 ///
 /// @file    Singleton.cc
 /// @author  ICIOfg
 /// @date    2018-04-21 15:53:45
 ///

#include "Singleton.h"
 
#include <iostream>
using std::cout;
using std::endl;
template<typename T>
T * Singleton<T>::_pInstance = NULL;

template<typename T>
template<typename t1, typename t2>
T * Singleton<T>::getInstance(const t1& lhs,const  t2& rhs)
{
	if(_pInstance==NULL)
	{
		_pInstance= new T(lhs, rhs);
	}
	return _pInstance;
}


