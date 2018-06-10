 ///
 /// @file    main.c
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-07 21:14:55
 ///
 
#include <iostream>
 
using namespace std;

class A
{
public:
	A(){}
	void * operator new()
	{
		auto p = malloc(1,sizeof(A));

	}
	void destroy()
	{
		this->~A();
	}
private:
	~A()
	{
		cout << "A" << endl;
	}
};

int main(){
	A aa;
	aa.destroy();
	return 0;
}
