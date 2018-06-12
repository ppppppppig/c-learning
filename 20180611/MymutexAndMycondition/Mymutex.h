 ///
 /// @file    Mymutex.h
 /// @author  ppppppppig(971896266@qq.com)
 /// @date    2018-06-11 21:07:51
 ///
#ifndef __MYMUTEX_H_
#define __MYMUTEX_H_

#include <pthread.h>

class Mymutex
{
public:
	Mymutex()
	{
		pthread_mutex_init(&mutex,NULL);
	}

	void lock()
	{
		pthread_mutex_lock(&mutex);
	}

	void unlock()
	{
		pthread_mutex_unlock(&mutex);
	}

	pthread_mutex_t &getmutex(){	return mutex;	}

	Mymutex(const Mymutex &) = delete;
	Mymutex &operator=(const Mymutex &) = delete;
	~Mymutex()
	{
		pthread_mutex_destroy(&mutex);
private:
	pthread_mutex_t mutex;
};

#endif
