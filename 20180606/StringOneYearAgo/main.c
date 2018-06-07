 ///
 /// @file    main.c
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-06 08:50:00
 ///
 
#include <iostream>
#include "String.h"
#include <stdio.h>
#include <string.h>

using namespace std;
 
int main(){
	String s;
	s.push_back('c');
	s.push_back('s');
	s.push_back('s');
	auto p=s.c_str();
	cout << s.capacity() << endl;
	cout << p[3] << endl;
	puts(p);
	return 0;
}
