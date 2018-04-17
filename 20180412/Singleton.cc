 ///
 /// @file    Singleton.cc
 /// @author  ICIOfg
 /// @date    2018-04-12 17:53:31
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Singleton
{
	
		static Singleton * _pInstance;
		Singleton(){ cout << "Singleton()" << endl;}
		~Singleton(){ cout << "~Singleton()" << endl;}
	public:
		static Singleton * getInstance()
		{
			if(_pInstance== NULL)
			{
				_pInstance = new Singleton;
			}
			return _pInstance;
		}

		static void destroy()
		{
			if(_pInstance)
			{
				delete _pInstance;
			}

		}
};

Singleton * Singleton::_pInstance =NULL;

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	cout << "p1" << p1 << endl;
	Singleton * p2 = Singleton::getInstance();
	cout << "p2" << p2 << endl;

	Singleton::destroy();

	return 0;
}
		


