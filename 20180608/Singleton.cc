 ///
 /// @file    Singleton.cc
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-07 21:12:01
 ///

#include <stdio.h>
#include <iostream>
 
using namespace std;
 
class Singleton
{
public:
	static Singleton * getInstance()
	{
		if(_pInstance == NULL)
		{
			_pInstance = new Singleton();
		}
		return _pInstance;
	}

	static void destroy()
	{
		if(_pInstance)
		{
			delete _pInstance;
		}
	}

private:
	Singleton()
	{
		cout<< "Singleton()" << endl;
	}
	~Singleton()
	{
		cout << "~Singleton()" << endl;
	}
private:
	static Singleton * _pInstance;
};

int main(){
 
	return 0;
}
