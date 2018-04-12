 ///
 /// @file    student.cpp
 /// @author  ICIOfg
 /// @date    2018-04-11 08:26:12
 ///
 
/q/创建文件student.cpp,并在文件中定义setinfo和display的成员函数实现
#include <string.h>
#include <iostream>
using namespace std;
//创建文件student.h，并在文件中声明类
class CSstudent
{
	private:
		int m_iId;
		char m_szName[32];
	public:

		void SetInfo(int iId,char *pszName);

		void Display();
};

void CSstudent::SetInfo(int iId, char * pszName)
{
	m_iId=iId;
	strcpy(m_szName, pszName);
}
void CSstudent::Display()
{
	cout << "the student named " << m_szName << "it's id is" << m_iId << endl;
}

int main(void)
{
	CSstudent stud;
	stud.SetInfo(3, "Tom");
	stud.Display();

	CSstudent *pstud = new CSstudent;
	pstud -> SetInfo(0, "Bill");
	pstud -> Display();

	(*pstud).Display();

	delete pstud;
	pstud = NULL;
}
