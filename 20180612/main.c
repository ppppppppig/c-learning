 ///
 /// @file    main.c
 /// @author  ppppppppig(971896266@qq.com)
 /// @date    2018-06-12 06:44:58
 ///
#include "String.h" 
#include <iostream>
using std::cout;
using std::endl;
using std::cin; 
int main()
{

	String s;
	cin >> s;
	cout << "s:" << s << endl;
	cout << s.c_str() << endl;
	String b = s;
	cout << b << endl;
	String c;
	c = b;
	cout << c << endl;
	return 0;
}
