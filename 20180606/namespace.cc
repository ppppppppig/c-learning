 ///
 /// @file    namespace.c
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-05 18:51:22
 ///
 
#include <iostream>
using std::cout;
using std::endl;

namespace A{
	void add(int a,int b){
		cout<<a+b<<endl;
	}
}

using namespace A;

void add(int a,int b,int c){
	cout<<a+b+c<<endl;
}

int main(){
	return 0;
}
