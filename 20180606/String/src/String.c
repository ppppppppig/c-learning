 ///
 /// @file    String.c
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-07 02:34:43
 ///

#include "String.h"


//静态变量需在类外定义
std::allocator<char> String::alloc;

void String::chk_range(const size_t sz) const
{
	if(sz > static_cast<size_t>(first_free - elements)) 
		throw out_of_range("");
}

void String::free()
{
	if(elements)
	{
		while(--first_free != elements)
		{
			alloc.destroy(first_free);
		}
		alloc.deallocate(elements , cap - elements);
	}
}

std::pair<char *,char *>
String::alloc_n_copy(const char *l,const char *r)
{
	char *newelem = alloc.allocate(r - l);
	return { newelem,std::uninitialized_copy(l,r,newelem) };
}

void String::reallocate()
{
	size_t sz = size() ? size() *2 :1;
	auto newelem = alloc.allocate(sz);
	auto oldelem = elements;
	elements = newelem;
	while(oldelem != first_free)
	{
		//这里实际上想要construct char 类型的对象
		alloc.construct(newelem++ , std::move(*oldelem++));
	}
	first_free = newelem;
	cap = elements + sz;
}

String::String(const char *b, const char *e)
{
	std::pair<char *,char *> sp = alloc_n_copy(b,e);
	elements = sp.first;
	first_free = cap = sp.second;
}


String::String(const char *p)
{
	size_t sz = 0;
	const char *now_p = p;
	while(*now_p++)
	{
		sz++;
	}
	elements = alloc.allocate(sz);
	auto newelem = elements;
	now_p = p;
	while(*now_p)
	{
		alloc.construct(newelem++,now_p++);
	}
}

String::String(const String &s)
{
	auto b = s.begin();
	auto e = s.end();
	std::pair<char *,char *> sp = alloc_n_copy(b,e);
	elements = sp.first;
	first_free = cap = sp.second;
}

String::String(String &&s) noexcept
{
	auto b = s.begin();
	auto e = s.end();
	auto newelem = alloc.allocate(e - b);
	elements = newelem;
	while(b != e)
	{
		alloc.construct(newelem++,std::move(*b++));
	}
	s.elements = s.first_free = s.cap = nullptr;
}

String& String::operator=(String &&s)noexcept
{
	if(this != &s)
	{
		free();
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		s.elements = s.first_free = s.cap = nullptr;
	}
	return *this;
}

String& String::operator=(const String &s)
{
	if(this != &s)
	{
		free();
		std::pair<char *,char *> sp = alloc_n_copy(s.begin(),s.end());
		elements = sp.first;;
		first_free = cap = sp.second;
	}
	return *this;
}


char & String::operator[](const size_t sz)
{
	chk_range(sz);
	return elements[sz];
}


const char & String::operator[](const size_t sz) const
{
	chk_range(sz);
	return elements[sz];
}


String::~String()
{
	free();
}


void String::push_back(const char &p)
{
	if(first_free == cap)
	{
		reallocate();
	}
	alloc.construct(first_free++,p);
}



const char * String::c_str() const
{
	if(!elements)
	{
		return "\0";
	}else{
		return elements;
	}
}



















