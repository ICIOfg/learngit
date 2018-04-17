 ///
 /// @file    text.cc
 /// @author  ICIOfg
 /// @date    2018-04-14 08:34:16
 ///
 
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;

void test0(void)
{
	int n1 = 10;
	int n2 = 20;
	stringstream ss;//字符串流
	ss << "n1=" << n1 << "n2=" << n2;
	//cout << ss << endl;//error, 不能直接输出缓冲流
	string str = ss.str(); //得到了字符串流中的缓冲区中的数据
	cout << str << endl;

	string word;
	int number;
	while(ss >> word >> number)
	{
		cout << word << " " << number << endl;
	}
}
//将整型数据转换成字符串
string itos(int number)
{
	ostringstream oss;
	oss << number;
	return oss.str();
}

void readConfiguration(const string & filename)
{
	ifstream ifs(filename);  //文件读入缓冲区,打开文件
	if(!ifs)
	{
		cout << "ifstream open error!" << endl;
		return;
	}

	string key;							//这么多缓冲区
										//数据交换需要在缓冲区进行？
	string value;
	string line;
	while(getline(ifs, line))    //从文件读入缓冲区读一行字符串
	{
		istringstream iss(line);   //将字符串放入字符串输入缓冲区
		iss >> key >> value;		//从缓冲区读出2个字符串分别
		cout << key << "-->" << value << endl;
	}

	ifs.close();   //关闭文件
}

int main( void)
{
	//test0();
	
	int i = 100;
	

	string w;
	w = i;
	cout << "w=" << w << endl;  //根据ascll码100输出d
	w = itos(i);
	cout << "w=" << w << endl;  //整形转换字符串后，输出字符串100

	string filename("confg.txt"); //将字符串路径赋给字符串filename
	readConfiguration(filename);


	return 0;
}




