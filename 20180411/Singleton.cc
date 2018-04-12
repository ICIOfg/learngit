 ///
 /// @file    Singleton.cc
 /// @author  ICIOfg
 /// @date    2018-04-12 17:00:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//单例设计模式，
//要求1：一个类只能创建一个对象（空间）
//要求2：该对象不能是栈对象/全局对象
//要求3：该对象只能是堆对象
//
class Singleton
{
	private://私有静态成员，只能被类内访问
		static Singleton * _pInstance;
	public:
		//静态构造函数，只能调用类内私有静态成员对象
		static Singleton * getInstance()
		{//创建私有成员对象空间，若已存在，则返回存在空间
			//则此类只会创建一个对象空间，要求1达标
			//创建的是申请的堆空间，要求2.3达标
			if(_pInstance == NULL)
			{
				_pInstance = new Singleton;
			}
			return _pInstance;
		}
		//因为是堆对象空间，则需自己手动释放空间
		//构造释放函数
		static void destroy()
		{
			if(_pInstance)
			{
				delete _pInstance;
			}
		}

	private:
		//会通过public函数类内调用私有对象的构造和析构函数
		Singleton() { cout << "Singleton()" << endl;}
		~Singleton() {cout << "~Singleton() " << endl;}

};

Singleton * Singleton::_pInstance= NULL;

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	cout << "p1 =" << p1 << endl;
	Singleton *p2 = Singleton::getInstance();

	cout << "p2 =" << p2 << endl;

	Singleton::destroy();
	return 0;
}





