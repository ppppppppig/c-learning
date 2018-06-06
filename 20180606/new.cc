 ///
 /// @file    new.cc
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-05 19:23:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
int main(){
	int *p=new int[10]();
	*(p+12)=12;
	cout<<*(p+12)<<endl;
	return 0;
}
