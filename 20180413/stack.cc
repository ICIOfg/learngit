 ///
 /// @file    stack.cc
 /// @author  ICIOfg
 /// @date    2018-04-13 20:11:17
 ///
 
#include <iostream>
#include <string.h>
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

class Stack
{
	char * _brand;
	int  _price ;

	public:

		Stack( const char * brand, int price)
		: _brand(new char[strlen(brand)+1]())
		, _price(price)
		{
			strcpy(_brand, brand);
			cout << "Stack(const char *, int)" << endl;
		}
		
		void print()
		{
			cout << "brand:" << _brand << endl;
			cout << "price:" << _price << endl;
		}

	private:	
		~Stack()
		{
			cout << "~Stack()" << endl;
		}

	public:
		void * operator new(size_t sz)
		{
			cout << "void * operator new(size_t sz)" << endl;
			void * ret = malloc(sz);
			return ret;
		}

		void destroy()
		{
			delete this;
		}

#if	1 
		void operator delete(void * ret)
		{
			cout << "void operator delete(void *)" << endl;
			free(ret);
		}
#endif

};

int main(void)
{
//	Stack com1("acer", 4000);
//	com1.print();

	Stack * pcom2 = new Stack("huawei",7000);
	pcom2->print();
	//delete pcom2 //堆空间需手动释放
	pcom2->destroy();
	return 0;
}
