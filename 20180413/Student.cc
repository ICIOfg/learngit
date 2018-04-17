 //
 /// @fill    Student.cc
 /// @author  ICIOfg
 /// @date    2018-04-13 10:56:36
 ///
#include <string.h> 
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::endl;

class Student
{
	public:
		
		Student(double id, const char * name)
		: _id(id)
		, _name(new char[strlen(name) + 1]())
		{
			strcpy(_name, name);
			cout << "Student()" << endl;
		}
		
		void print() const
		{
			cout << "id:" << _id << endl;
			cout << "name:" << _name << endl;
		}
		~Student()
		{
			cout << "~Student() " << endl;
		}
		//sz由系统完成传递
		void * operator new(size_t sz)
		{  //operator new 就是一个自定义开辟内存方式的接口
			cout << "void * operator new(size_t sz)" << endl;
			void * ret = malloc(sz);
			return ret;
		}

		void operator delete(void * ret)
		{
			cout << "void operator delete(void *)" << endl;
			free(ret);
		}



	private:

		double _id;
		char * _name;

};

int main(void)
{
	cout << "sizeof(Student)= " << sizeof(Student) << endl;

	Student * pstu = new Student(1001, "mak");
	pstu->print();

	delete pstu;
	return 0;
}
