 ///
 /// @file    staticInClass.c
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-06 20:59:49
 ///
 
#include <iostream>
 
using namespace std;

class A{
public:
	void print(){
		cout<<b<<endl;
	}
	void add(){
		b++;
		cout<<b<<endl;
	}
private:
	static int b;
};

int A::b=4;


int main(){
	A maxiao1;
	A maxiao2;
	cout << "maxiao1=";
	maxiao1.print();
	maxiao1.add();
	cout << "maxiao2=" ;
	maxiao2.print();
	return 0;
}
