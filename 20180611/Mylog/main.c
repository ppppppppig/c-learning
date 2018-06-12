 ///
 /// @file    main.c
 /// @author  ppppppppig(971896266@qq.com)
 /// @date    2018-06-11 08:42:55
 ///

#include "Mylog.h"
#include <iostream>
using std::cout;
using std::endl;

using namespace wd;

int main()
{
	Mylog *p = Mylog::getpInstance();
	const char *msg="i am gao ling xiao";
	p->warn(msg);
	p->error(msg);
	p->info(msg);
	p->debug(msg);
	return 0;
}
