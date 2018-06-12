 ///
 /// @file    onlyontclass.c
 /// @author  ppppppppig(971896266@qq.com)
 /// @date    2018-06-10 19:26:16
 ///
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using std::cout;
using std::endl;

class onlyoneclass
{
public:
	static onlyoneclass * getptr()
	{
		if(!_pmine)
		{
			_pmine = (onlyoneclass *) new onlyoneclass();
		}
		return _pmine;
	}

	static void destroy()
	{
		delete _pmine;
	}

private:
	onlyoneclass()
	{
		cout << "onlyoneclass" << endl;
	}

	~onlyoneclass()
	{
		cout << "~onlyoneclass" << endl;
		if(_pmine)
		{
			free(_pmine);
		}
	}

	static onlyoneclass * _pmine;
};

onlyoneclass * onlyoneclass::_pmine = NULL;

int main()
{

	return 0;
}
