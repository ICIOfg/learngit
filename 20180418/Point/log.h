 ///
 /// @file    log.h
 /// @author  ICIOfg
 /// @date    2018-04-16 19:45:06
 ///

#ifndef __LOG_H__
#define __LOG_H__
#include <string>
#include <sstream>
#include <log4cpp/Category.hh>

using std::string;

class Logd
{
	public:
		static Logd * getInstance();
		static void destroy();

		void Info(const char * mes);
		void Error(const char * mes);
		
		void Warn(const char * mes);
		void Debug(const char * mes);


	private:

		Logd();
		~Logd();

		static Logd * _pInstance;
		log4cpp::Category & _root;
};
inline string int2str(int number)
{
	std::ostringstream oss;
	oss << number;
	return oss.str();
}

#define prefix(mes) string("[").append(__FILE__)\
					.append(":").append(__FUNCTION__)\
					.append(":").append(int2str(__LINE__))\
					.append("]").append(mes).c_str()


#define logWarn(mes) Logd::getInstance()->Warn(prefix(mes))
#define logInfo(mes) Logd::getInstance()->Info(prefix(mes))
#define logError(mes) Logd::getInstance()->Error(prefix(mes))
#define logDebug(mes) Logd::getInstance()->Debug(prefix(mes))


#endif
