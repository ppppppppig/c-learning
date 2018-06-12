 ///
 /// @file    pratice.c
 /// @author  ppppppppig(971896266@qq.com)
 /// @date    2018-06-11 19:03:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
void test0()
{
	cout << __FILE__ << endl
		 << __FUNCTION__ << endl
		 << __LINE__ << endl;
}

int main()
{
	test0(); 
	return 0;
}
