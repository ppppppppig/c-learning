 ///
 /// @file    test.cc
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-10 05:43:06
 ///
 
#include <iostream>
#include <fstream>
#include <assert.h>

using namespace std;
 
int main(){
	ifstream in("test.txt");
	in.seekg(0,ios::end);
	int cc = in.tellg();
	cout << cc << endl;
	return 0;
}
