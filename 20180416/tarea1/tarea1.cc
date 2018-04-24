 ///
 /// @file    tarea1.cc
 /// @author  ICIOfg
 /// @date    2018-04-16 19:39:30
 ///



#include "log.h"

#include <iostream>
#include <string>


void test(void)
{
	Logd::getInstance()->Info("info message");
	Logd::getInstance()->Warn("warn message");
	Logd::getInstance()->Error("error message");
	Logd::getInstance()->Debug("debug message");

	Logd::destroy();
}

void test1(void)
{
	logWarn("warn message");
	logInfo("info message");
	logError("error message");
	logDebug("debug message");


	Logd::destroy();
}


int main(void)
{
	//test();
	test1();
	return 0;
}

