 ///
 /// @file    Logd.cc
 /// @author  ICIOfg
 /// @date    2018-04-16 20:00:22
 ///

#include "log.h"

#include <iostream>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
using std::cout;
using std::endl;

Logd * Logd::_pInstance = NULL; //nullptr;

Logd * Logd::getInstance()
{
	if(!_pInstance)
	{
		_pInstance = new Logd();
	}
	return _pInstance;
}

void Logd::destroy()
{
	if(_pInstance)
	{
		delete _pInstance;
	}
}


Logd::Logd()
:_root(log4cpp::Category::getRoot())
{
	//创建两套输出布局，一个给ostreamAppender，一个给FileAppender
	log4cpp::PatternLayout * put1 = new log4cpp::PatternLayout();
	put1->setConversionPattern("%d:%p %c %x: %m%n");


	log4cpp::PatternLayout * put2 = new log4cpp::PatternLayout();
	put2->setConversionPattern("%d:%p %c %x: %m%n");

	//建两个输出位置，一个&cout给osAppender， 一个输出日志文件位置给Fileappender,并分别赋予其输出布局
	
	log4cpp::OstreamAppender * osAppender = new log4cpp::OstreamAppender("osAppender",&cout);
	osAppender->setLayout(put1);

	log4cpp::FileAppender * fileAppender = new log4cpp::FileAppender("fileAppender","lgd.log");
	fileAppender->setLayout(put2);

	//将两个输出加入root
	//root在构造函数对象初始化列表已得出
	//
	_root.addAppender(osAppender);
	_root.addAppender(fileAppender);

	//设置root优先级
	
	_root.setPriority(log4cpp::Priority::DEBUG);

}
	


Logd::~Logd()
{
	log4cpp::Category::shutdown();
}

void Logd::Warn(const char* mes)
{
	_root.warn(mes);
}
void Logd::Error(const char* mes)
{
	_root.error(mes);
}

void Logd::Info(const char* mes)
{
	_root.info(mes);
}
void Logd::Debug(const char* mes)
{
	_root.debug(mes);
}
