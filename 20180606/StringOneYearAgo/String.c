///
/// @file    String.c
/// @author  ppppppppig (971896266@qq.com)
/// @date    2018-06-06 06:55:36
///




#include "String.h"


std::allocator<char> String::alloc;
void String::free()
{
	//从后向前销毁元素
	if (elements)
	{
		while (first_free != elements)
			alloc.destroy(--first_free);
		alloc.deallocate(elements, cap - elements);
	}
}


void String::reallocate()
{
	cout << "reallocate" << endl;
	//内存分配策略
	size_t newString = size() ? size() * 2 : 1;
	char *newfree = alloc.allocate(newString);
	char *oldelem = elements;
	elements = newfree;
	//std::move将一个左值变成右值
	while (oldelem != first_free)
		alloc.construct(newfree++, std::move(*oldelem++));
	first_free = newfree;
	cap = elements + newString;
}


std::pair<char*, char*> String::alloc_n_copy(const char *b, const char *e)
{
	char *newelem = alloc.allocate(e - b);
	return{ newelem,std::uninitialized_copy(b,e,newelem) };
}

String::String(const char *b,const char *e)
{
	elements = alloc.allocate(e - b);
	first_free = cap = e - b + elements;
}

String::String(const String &m)
{
	cout << "a o a o ao ao ao!" << endl;
	auto p = alloc_n_copy(m.begin(),m.end());
	elements = p.first;
	cap = first_free = p.second;
}

String& String::operator=(const String &rhs)
{
	cout << "bi bu bi bu bi bu!" << endl;
	free();
	auto p = alloc_n_copy(rhs.begin(), rhs.end());
	elements = p.first;
	cap = first_free = p.second;
	return *this;
}

String::~String()
{
	free();
}


String::String(const char *p)
{
	//根据c语言字符串来构造函数
	size_t sz = 0;
	for (const char *b = p; *b; ++b)
		++sz;
	auto elem = alloc.allocate(sz);
	std::uninitialized_copy(p, p + sz, elem);
	elements = elem;
	first_free = cap = elem + sz;
}


String::String(String &&m) noexcept:elements(m.elements), first_free(m.first_free), cap(m.cap)//移动构造函数
{
	cout << "嘎嘣脆，鸡肉味！" << endl;
	m.elements = m.first_free = m.cap = nullptr;
}

String& String::operator=(String &&rhs) noexcept//移动赋值运算符
{
	if (this != &rhs)//自赋值检查
	{
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.elements = rhs.cap = nullptr;
	}
	return *this;
}

ostream &operator<<(ostream &os, const String &s)
{
	auto now = s.elements;
	while (now != s.first_free)
		os << *now++;
	return os;
}

bool operator==(const String &a, const String &b)
{
	if (a.size() == b.size())
	{
		auto *pa = a.begin();
		auto *pb = b.begin();
		while (pa != a.end())
		{
			if (*pa++ != *pb++)
				return false;
		}
		return true;
	}
	return false;
}

bool operator!=(const String &a, const String &b)
{
	return !(a == b);
}

bool operator<(const String &a, const String &b)
{
	auto *pa = a.begin();
	auto *pb = b.begin();
	while (pa != a.end()&&pb!=b.end())
	{
		if (*pa++ > *pb++)
			return false;
	}
	if (a.size() < b.size()) return true;
	return false;
}


char& String::operator[](const size_t sz)
{
	chk_range(sz);
	return elements[sz];
}

const char& String::operator[](const size_t sz) const
{
	chk_range(sz);
	return elements[sz];
}

const char * String::c_str() const
{
	if(elements==first_free)
		return "\0";
	else {
		return elements;
	}
}

void String::chk_range(const size_t sz) const
{
	if (sz > size())
		throw std::out_of_range("");
}
