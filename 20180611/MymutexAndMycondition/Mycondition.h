 ///
 /// @file    Mycondition.h
 /// @author  ppppppppig(971896266@qq.com)
 /// @date    2018-06-11 21:18:39
 ///


#ifndef __MYCONDITION_H_
#define __MYCONDITION_H_

#include <pthread.h>

class Mymutex;

class Mycondition
{
public:

	Mycondition()
	:_mymutex()
	{
		pthread_cond_init(&_cond,NULL);
	}
	void wait();
	void notify();
	void notifyall();

	~Mycondition()
	{
		pthread_cond_destroy(_cond);
		//会自动执行_Mymutex的析构函数
	}
private:

	pthread_cond_t _cond;
	Mymutex _mymutex;
};


#endif
