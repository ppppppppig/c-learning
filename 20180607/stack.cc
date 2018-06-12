 ///
 /// @file    stack.cc
 /// @author  ppppppppig(971896266@qq.com)
 /// @date    2018-06-10 07:17:41
 ///
 
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

class stack
{
public:
	stack()
	:size(0)
	{
	}
	stack(const stack &p)
	:size(p.size)
	{
		for(int i = 0;i < size;i++)
		{
			a[i] = p.a[i];
		}
	}
	void push(int b)
	{
		if(size == 10)
		{
			cout << "too much" << endl;
		}
		a[size++] = b;
	}
	void pop()
	{
		if(size == 0)
		{
			cout << "no date" << endl;
		}
		size--;
	}
	int top()
	{
		return a[size - 1];
	}
	bool empty()
	{
		if(size != 0)
		{
			return true;
		}
		return false;
	}
	bool full()
	{
		if(size == 10)
		{
			return true;
		}
		return false;
	}
private:
	int a[10];
	int size;
};

int main()
{
	stack s;
	s.push(10);
	cout << s.top() << endl;
	s.push(12);
	cout << s.top() << endl;
	s.push(14);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() <<endl;
	s.pop();
	return 0;
}
