 ///
 /// @file    Mycondition.cc
 /// @author  ppppppppig(971896266@qq.com)
 /// @date    2018-06-11 21:31:57
 ///

#include "Mycondition.h"
#include "Mymutex.h"

void Mycondition::wait()
{
	pthread_cond_wait(&_cond,&_mymutex.getmutex());
}

void Mycondition::notify()
{
	_pthread_cond_signal(&_cond);
}


