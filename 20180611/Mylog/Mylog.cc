 ///
 /// @file    Mylog.cc
 /// @author  ppppppppig(971896266@qq.com)
 /// @date    2018-06-11 08:21:00
 ///
#include "Mylog.h"

#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

#include <iostream>

using namespace wd;
using std::cout;
using std::endl;

Mylog * Mylog::_pInstance = NULL;

Mylog * Mylog::getpInstance()
{
	if(!_pInstance)
	{
		_pInstance = new Mylog();
	}
	return _pInstance;
}


void Mylog::destroy()
{
	if(_pInstance)
	{
		delete _pInstance;
	}
}

void Mylog::warn(const char * msg)
{
		_root.warn(msg);
}


void Mylog::info(const char * msg)
{
		_root.info(msg);
}

void Mylog::error(const char * msg)
{
		_root.error(msg);
}

void Mylog::debug(const char * msg)
{
		_root.debug(msg);
}

Mylog::Mylog()
:_root(Category::getRoot().getInstance("root"))
{
	PatternLayout *	ptnLyout1 = new PatternLayout();
	PatternLayout * ptnLyout2 = new PatternLayout();
	ptnLyout1->setConversionPattern("%d [%p] %m%n");
	ptnLyout2->setConversionPattern("%d [%p] %m%n");

	OstreamAppender * ostreamAppender = new OstreamAppender("ostreamappender",&cout);
	ostreamAppender->setLayout(ptnLyout1);
	FileAppender * fileAppender = new FileAppender("fileappender","wangdao.txt");
	fileAppender->setLayout(ptnLyout2);

	_root.addAppender(ostreamAppender);
	_root.addAppender(fileAppender);
	_root.setPriority(Priority::DEBUG);
}

Mylog::~Mylog()
{
	Category::shutdown();
}

