 ///
 /// @file    main.c
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-07 02:32:13
 ///
 
#include <iostream>
#include "String.h"

using namespace std;
 
int main(){
	String s;
	String s1("12345");
	String s2(std::move(s1));

	return 0;
}
