 ///
 /// @file    main.c
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-06 08:50:00
 ///
 
#include <iostream>
#include "String.h"
#include <stdio.h>

using namespace std;
 
int main(){
	String s2("the beautiful world");
	String s(s2.begin(),s2.end());
	const char *ps=s.c_str();
	cout << ps ;
	return 0;
}
