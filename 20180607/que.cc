 ///
 /// @file    que.cc
 /// @author  ppppppppig(971896266@qq.com)
 /// @date    2018-06-10 07:33:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class que
{
public:
	que()
	:f(0)
	,e(0)
	,size(0)
	{
	}
	que(const que &cc)
	:f(cc.f)
	,e(cc.e)
	,size(cc.size)
	{
		for(int i = 0;i < size;i++)
		{
			int pos = (i + f) % 10;
			a[pos] = cc.a[pos];
		}
	}

	void push(int bb)
	{
		if(full())
		{
			return ;
		}
		a[e] = bb;
		size++;
		e = (f + size) % 10;
	}

	void pop()
	{
		if(empty())
		{
			return ;
		}
		--size;
		f = (f + 1) % 10;
	}

	int front ()
	{
		if(empty())
		{
			return -1;
		}
		return a[f];
	}

	int back()
	{
		if(empty())
		{
			return -1;
		}
		return a[(e + 9) % 10];
	}
	bool empty()
	{
		if(size == 0)
		{
			cout << "que emtpy" << endl;
			return true;
		}
		return false;
	}

	bool full()
	{
		if(size == 10)
		{
			cout << "que full" << endl;
			return true;
		}
		return false;
	}
private:
	int a[10];
	int f,e;
	int size;
};


int main()
{
	que q;
	q.push(10);
	q.push(11);
	q.push(12);
	q.push(10);
	q.push(10);
	q.push(10);
	q.push(11);
	q.push(12);
	q.push(11);
	q.push(12);
	q.push(11);
	q.push(12);
	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	q.pop();
	cout << q.front() << endl;
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.push(100);
	q.push(200);
	cout << q.back() << endl;
	return 0;
}
