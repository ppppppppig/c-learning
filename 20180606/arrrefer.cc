 ///
 /// @file    arrrefer.c
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-06 01:18:42
 ///
 
#include <iostream>
 
using namespace std;
 
int main(){
	int arr[10];
	int (&ra)[10]=arr;
	ra[3]=3;
	cout << ra[3] << arr[3] << endl;
	return 0;
}
