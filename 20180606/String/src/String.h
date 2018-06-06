 ///
 /// @file    String.h
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-06 05:24:18
 ///

#ifndef __STRING_H_
#define __STRING_H_

#include <string.h>
#include <iostream>

using std::ostream;
using std::istream;

class String{
	friend String operator + (const String &,const String &);
	friend ostream & operator<< (ostream &,const String &);
	friend istream & operator>> (istream &,const String &);
public:
//String 
	String()
	:ps(nullptr)
	{}
//String 拷贝构造函数
	String(const String &s);
//String 拷贝赋值运算符
	String &operator = (const String&);
	void push_back(const char &c);
	char * c_str();
	size_t size();
	void append(const String &);
	~String();
private:
	size_t len;
	size_t capacity;
	char * ps;
};
String operator + (const String &,const String &);
ostream & operator<< (ostream &,const String &);
istream & operator>> (istream &,const String &);

#endif 
