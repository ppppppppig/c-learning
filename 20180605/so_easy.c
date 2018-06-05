 ///
 /// @file    so_easy.c
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-05 01:57:59
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main(){
	int *pa;
	pa=new int[100]();
	cout<<"*pa = "<<*pa<<endl;
	//delete pa;  //不能这么做，结果是未定义的
	delete [] pa;
	return 0;
}
