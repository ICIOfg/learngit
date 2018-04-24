 ///
 /// @file    readRss.cpp
 /// @author  ICIOfg
 /// @date    2018-04-23 19:28:33
 ///


#include "tinyxml2.h"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

void test0(void)
{
	using namespace tinyxml2;

	XMLDocument doc;
	doc.LoadFile("coolshell.xml");
	cout << "1 ok" << endl;
	XMLElement * proot = doc.FirstChildElement("rss");
	cout << "2 ok" << endl;
	XMLElement * pchannel = proot ->FirstChildElement("channel");
	cout << "3 ok" << endl;
	XMLElement * pitem = pchannel ->FirstChildElement("item");
	cout << "4 ok" << endl;
	XMLElement * ptitle = pitem -> FirstChildElement("title");
	cout << "5 ok" << endl;
	XMLElement * plink = ptitle -> FirstChildElement("link");
	cout << "6 ok" << endl;
	XMLElement * pdescription = pitem ->FirstChildElement("pdescription");
	cout << "7 ok" << endl;
	XMLElement * pcontent = pitem -> FirstChildElement("content:encoded");
	cout << "8 ok" << endl;

	string title;
	string link;
	string description;
	string content;

	if(ptitle)
		title = string(ptitle->GetText());
	if(plink)
		link = string(plink-> GetText());
	if(pdescription)
		description = string(pdescription ->GetText());
	if(pcontent)
		content = string(pcontent ->GetText());
	cout << "9 ok" << endl;
	cout << "title:" << title << endl
		<< "link:" <<link << endl
		<< "description:" << description << endl
		<< "content:" << content << endl;
}


int main(void)
{
	test0();
	return 0;
}



	
