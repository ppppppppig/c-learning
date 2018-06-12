///
/// @file    String.h
/// @author  ppppppppig(971896266@qq.com)
/// @date    2018-06-12 05:51:03
///

#ifndef __STRING_H_
#define __STRING_H_

#include <iostream>

class String {
	public:
		String();
		String(const char *);
		String(const String&);
		~String();
		String &operator=(const String &);
		String &operator=(const char *);

		String &operator+=(const String &);
		String &operator+=(const char *);

		char &operator[](std::size_t index);
		const char &operator[](std::size_t index) const;

		std::size_t size() const;
		const char* c_str() const;

		friend bool operator==(const String &, const String &);
		friend bool operator!=(const String &, const String &);

		friend bool operator<(const String &, const String &);
		friend bool operator>(const String &, const String &);
		friend bool operator<=(const String &, const String &);
		friend bool operator>=(const String &, const String &);

		friend std::ostream &operator<<(std::ostream &os, const String &s);
		friend std::istream &operator>>(std::istream &is, String &s);

	private:
		void reallocate();
		char * _pstr;
};

String operator+(const String &, const String &);
String operator+(const String &, const char *);
String operator+(const char *, const String &);




#endif
