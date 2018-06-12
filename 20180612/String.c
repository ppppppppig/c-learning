 ///
 /// @file    String.c
 /// @author  ppppppppig(971896266@qq.com)
 /// @date    2018-06-12 05:52:21
 ///

#include "String.h"
#include <string.h>
#include <iostream>

using std::size_t;
using std::endl;
using std::cout;

char &String::operator[](size_t index)
{
	if(index >= size()||index < 0)
	{
		cout << "越界错" << endl;
	}
	return _pstr[index];
}


const char &String::operator[](size_t index) const
{
	if(index >= size()||index < 0)
	{
		cout << "越界错" << endl;
		//return '\0';
	}
	return _pstr[index];
}

size_t String::size() const
{
	if(!_pstr) return 0;
	return strlen(_pstr);
}


String::String()//默认构造函数
:_pstr(NULL)
{}

String::String(const char *s)//带一个参数的构造函数
:_pstr(new char[strlen(s)]())
{
	size_t sz = strlen(s);
	for(int i = 0;i < sz;++i)
	{
		_pstr[i] = s[i];
	}
}
//拷贝构造函数
String::String(const String &s)
:_pstr(new char[s.size()]())
{
	size_t sz = s.size();
	for(int i = 0;i < sz;++i)
	{
		_pstr[i] = s[i];
	}
}

String::~String()
{
	delete _pstr;
}

String &String::operator=(const String &s)
{
	//赋值构造函数的三要素：
	//1.销毁原空间
	//2.自赋值问题
	//3.深拷贝问题
	delete _pstr;
	_pstr = NULL;
	if(&s != this)
	{
		_pstr = new char[s.size()]();
		size_t sz = s.size();
		for(size_t i = 0;i < sz;++i)
		{
			_pstr[i] = s[i];
		}
	}
	return *this;
}


String &String::operator=(const char *s)
{
	delete _pstr;
	_pstr = NULL;
	size_t sz = strlen(s);
	_pstr = new char[sz]();
	for(int i = 0;i < sz;++i)
	{
		_pstr[i] = s[i];
	}
	return *this;
}

String &String::operator+=(const String &s)
{
	//1.新创建一个足以容纳两个字符串的空间
	//2.将字符串拷贝过去
	//3.将原空间销毁
	size_t sz1 = size();
	size_t sz = sz1 + s.size();
	char * _pnew = new char[sz]();
	for(size_t idx = 0;idx < sz1;++idx)
	{
		_pnew[idx] = _pstr[idx];
	}
	for(size_t idx = 0;idx < s.size();++idx)
	{
		_pnew[idx + sz1] = s[idx];
	}
	delete _pstr;
	_pstr = _pnew;
	return *this;
}


String &String::operator+=(const char *s)
{
	size_t sz1 = size();
	size_t sz = sz1 + strlen(s);
	char * _pnew = new char[sz]();
	for(size_t idx = 0;idx < sz1;++idx)
	{
		_pnew[idx] = _pstr[idx];
	}
	for(size_t idx = 0;idx < strlen(s);++idx)
	{
		_pnew[idx + sz1] = s[idx];
	}
	delete _pstr;
	_pstr = _pnew;
	return *this;
}


const char *String::c_str() const
{
	return _pstr;
}

bool operator==(const String &lhs,const String &rhs)
{
	if(lhs.size() == rhs.size())
	{
		size_t sz = lhs.size();
		for(size_t idx = 0;idx < sz;++idx)
		{
			if(lhs[idx] != rhs[idx])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}


bool operator!=(const String &lhs,const String &rhs)
{
	return ~(lhs == rhs);
}


bool operator<(const String &lhs, const String &rhs)
{
	int bigger = strcmp(lhs.c_str(),rhs.c_str());
	if( bigger < 0)
	{
		return true;
	}
	return false;
}

bool operator>(const String &lhs, const String &rhs)
{
	int bigger = strcmp(lhs.c_str(),rhs.c_str());
	if( bigger > 0)
	{
		return true;
	}
	return false;
}

bool operator<=(const String &lhs, const String &rhs)
{

	return ~(lhs > rhs);
}


bool operator>=(const String &lhs, const String &rhs){
	return ~(lhs < rhs);
}


std::ostream &operator<<(std::ostream &os,const String &s)
{
	size_t sz = s.size();
	for(size_t idx = 0;idx < sz;++idx)
	{
		os << s._pstr[idx];
	}
	return os;
}

void String::reallocate()
{
	size_t past_sz = size();
	size_t sz = size()?size() *2 :1;
	char * _pnew = new char[sz]();
	memset(_pnew,0,sizeof(char) * sz);
	for(size_t idx = 0; idx < past_sz;++idx)
	{
		_pnew[idx] = _pstr[idx];
	}
	delete _pstr;
	_pstr = _pnew;
}

std::istream &operator>>(std::istream &is,String &s)
{
	//1.s._ptr为NULL是，申请空间
	//2.s._ptr指向的内存存满时，新开辟一个两倍大小的空间，将原空间内存数据拷贝过去，然后销毁
	if(!s._pstr)
	{
		s.reallocate();
	}
	size_t cnt = 0;
	char ch;
	while((ch = is.get())!='\n')
	{
		if(cnt == s.size())
		{
			s.reallocate();
		}
		s._pstr[cnt] = ch;
		++cnt;
	}

}
