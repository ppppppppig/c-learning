 ///
 /// @file    pratice.c
 /// @ ppppppppig (971896266@qq.com)
 /// @date    2018-06-05 00:44:47
 ///
 
#include <stdio.h>
using std::cout;
using std::endl;
#ifdef __cplusplus
extern "C"{
#endif
int add(int a,int b){
	return a+b;
}
#ifdef __cplusplus
}
#endif

int main(){
	int a=3,b=4;
	cout<<"a + b = "<<add(a,b)<<endl;
	return 0;
}
