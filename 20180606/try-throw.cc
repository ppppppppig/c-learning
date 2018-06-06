 ///
 /// @file    try-throw.cc
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-06 01:10:58
 ///
 
#include <iostream>

using namespace std;
 
int main(){
	try{
		int a[10];
		cout<<a[12]<<endl;
		throw runtime_error("数组越界");
	}catch(runtime_error err){
		cout<<err.what()<<endl;
	}
	return 0;
}
