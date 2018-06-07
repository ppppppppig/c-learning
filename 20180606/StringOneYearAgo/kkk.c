 ///
 /// @file    kkk.c
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-07 06:36:45
 ///
 
#include <iostream>
#include <memory> 
#include <stdio.h>
using namespace std;
 
int main(){
	allocator<int> alloc;
	int * pp = alloc.allocate(4);
	printf("%d\n",*pp);
	return 0;
}
