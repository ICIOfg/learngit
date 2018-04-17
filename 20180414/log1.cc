 ///
 /// @file    log1.cc
 /// @author  ICIOfg
 /// @date    2018-04-16 09:30:17
 ///
 
#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>

using std::cout;
using std::endl;




int main(void)
{
	cout << "hello,world" << endl;
	log4cpp::OstreamAppender* osAppender = new log4cpp::OstreamAppender("osAppender", &cout);
	osAppender->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category & root = log4cpp::Category::getRoot();
	root.addAppender(osAppender);



	logInfo("Message");
	logError("Message");
	logWarn("Message");
	logDebug("Message");
}
