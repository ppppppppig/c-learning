///
/// @file    String.h
/// @author  ppppppppig (971896266@qq.com)
/// @date    2018-06-06 06:59:38
///

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory>

using namespace std;

class String
{
	friend ostream &operator<<(ostream &os, const String &s);
	friend bool operator==(const String &a, const String &b);
	friend bool operator!=(const String &a, const String &b);
	friend bool operator<(const String &a, const String &b);
public:
	String() :elements(nullptr), first_free(nullptr), cap(nullptr) {}
	//function don't complete
	String(const char *b, const char *e);
	//根据C语言字符串来构造函数
	String(const char *p);
	//拷贝构造函数
	String(const String &);
	String(String &&)noexcept;//移动构造函数
	String& operator=(String &&)noexcept;//移动赋值运算符
	String& operator=(const String &);
	char& operator[](const size_t);//这个只对非常亮String有效，所以不加const限定符
	const char& operator[](const size_t) const;
	~String();
	void push_back(const char &);
	size_t capacity() const { return cap - elements; }
	size_t size() const { return first_free - elements; }
	char *begin() const { return elements; }//如果没有const类型修饰符，那么const类型的类不能使用该成员。
	char *end() const { return first_free; }
	const char* c_str() const;
private:
	static std::allocator<char> alloc;
	void cheak()
	{
		if (capacity() == size())
			reallocate();
	}
	void chk_range(const size_t) const;
	void free();
	
	void reallocate();
	//拷贝b到e的元素并返回
	std::pair<char*,char*> alloc_n_copy(const char*,const char*);
	char *elements;//指向String的第一个元素
	char *first_free;//最后一个元素后的地址
	char *cap;//最后一个元素
};
