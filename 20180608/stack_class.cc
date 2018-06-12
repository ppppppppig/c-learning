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
private:
	void * operator new (size_t );
	void operator delete (void *);
	void * operator new[] (size_t);
	int a;
};

int main()
{
	onlystack a;
	onlystack * p = (onlystack *) new onlystack[10];
	return 0;
}
