 ///
 /// @file    Sing.cc
 /// @author  ICIOfg
 /// @date    2018-04-18 15:04:15
 ///
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

//单例对象自动释放方法1
//嵌套类+静态对象

//单例对象自动释放方法二
//必须要在linux环境下使用，因为关联了posix线程库
//atexit+pthread_once

class Singleton
{
	public:
	//在多线程环境下是非线程安全的
	//多线程可能一起拿到new任务，会得到多空间，内存泄漏
	//1.可以加线程锁
	//2.在初始化时候调用getInstance函数创建空间


		static Singleton * getInstance()
		{
			if(NULL == _pInstance)
			{
				_pInstance= new Singleton;
			}
			return _pInstance;
		}
		
		//只会执行一次
		
		static void init()
		{
			_pInstance= new Singleton;
			::atexit(destroy);
		}






#if 1
		static void destroy()
		{
			if(_pInstance)
			{
				delete _pInstance;
			}
		}
#endif                                                                                                           
	private:
		Singleton()
		{
			cout << "Singleton()" << endl;
		}
		~Singleton()
		{
			cout << "~Singleton()" << endl;
		}
		static Singleton* _pInstance;
		
		static pthread_once_t _once;
//		static autoRelease _auto;
};
//Singleton* Singleton::_pInstance;//饿汉模式,,多线程使用时需加锁
Singleton * Singleton::_pInstance;//=getInstance() // =NULL;
								//线程安全的，饱汉模式
//Singleton::autoRelease Singleton::_auto;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void)
{
	Singleton * p1= Singleton::getInstance();
	Singleton * p2= Singleton::getInstance();
	cout << "p1=" << p1 << endl;
	cout << "p2=" << p2 << endl;

//	Singleton::destroy();    //有了auto可以自动执行delete操
	return 0;
}
