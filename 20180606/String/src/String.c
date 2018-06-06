 ///
 /// @file    String.c
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-06 05:52:04
 ///

#include "String.h"

String operator + (const String &lhs,const String &rhs){
	return lhs.append(rhs);
}

ostream & operator << (ostream & os,const String &s){
	os << s.ps;
	return os;
}

istream & operator << (istream & is , const String &s){
	is >> s.ps;
	s.len = strlen(s.ps);
	return is;
}

String::String(const String &s)
:ps(new char[strlen(s.ps)]())
,len(strlen(s.ps))
{
	cout << "String" << endl;
	for(size_t i = 0;i < len;i++){
		*(ps + i) = *(s.ps + i);
	}
}

String String::&operator = (const String &s)
{
	cout << "operator = " << endl;
	this->len = s.len;
	this->ps = new char[len]();
	for(size_t i = 0;i < len;i++){
		*(ps + i) = *(s.ps + i);
	}
}
	
void String::push_back(const char &c){
	s.











