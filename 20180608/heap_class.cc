 ///
 /// @file    stack_class.cc
 /// @author  ppppppppig(971896266@qq.com)
 /// @date    2018-06-10 08:06:51
 ///
 
#include <iostream>

using std::cout;
using std::endl;

class onlystack
{
public:
	onlystack()
	:a(0)
	{
	}
	void dd(onlystack &s) const
	{
		s.a = 10;
	}
	static void destroy(onlystack *p)
	{
		delete p;
	}
private:
	~onlystack()
	{
		cout << "~onlystack()" << endl;
	}
	int a;
};

int main()
{
	onlystack * p = (onlystack *) new onlystack;
	onlystack::destroy(p);
	return 0;
}
