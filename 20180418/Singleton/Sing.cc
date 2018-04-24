 ///
 /// @file    Sing.cc
 /// @author  ICIOfg
 /// @date    2018-04-18 15:04:15
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//单例对象自动释放方法1
//嵌套类+静态对象



class Singleton
{
	class autoRelease
	{
		public:
			autoRelease()
			{
				cout << "autoRelease()" << endl;
			}
			~autoRelease()
			{
				if(_pInstance)
				{
					delete _pInstance;
					cout << "~autoRelease()" << endl;
				}

			}

	};
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
#if 0
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

		static autoRelease _auto;
};
//Singleton* Singleton::_pInstance;//饿汉模式,,多线程使用时需加锁
Singleton * Singleton::_pInstance;//=getInstance() // =NULL;
								//线程安全的，饱汉模式
Singleton::autoRelease Singleton::_auto;

int main(void)
{
	Singleton * p1= Singleton::getInstance();
	Singleton * p2= Singleton::getInstance();
	cout << "p1=" << p1 << endl;
	cout << "p2=" << p2 << endl;

//	Singleton::destroy();    //有了auto可以自动执行delete操
	return 0;
}
