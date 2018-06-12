///
/// @file    Mylog.h
/// @author  ppppppppig(971896266@qq.com)
/// @date    2018-06-11 08:14:11
///

#ifndef __MYLOG_H_
#define __MYLOG_H_

#include <log4cpp/Category.hh>
#include <iostream>

using namespace log4cpp;

namespace wd
{
class Mylog
{
public:
	static Mylog * getpInstance();
	static void destroy();
	
	void warn(const char * );
	void error(const char *);
	void info(const char *);
	void debug(const char *);

private:
	Mylog();
	~Mylog();
private:
	Category & _root;//为什么要定义成引用
	static Mylog * _pInstance;
};

}//end of namespace wd

#endif
