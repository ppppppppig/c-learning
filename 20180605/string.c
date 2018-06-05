 ///
 /// @file    string.c
 /// @author  ppppppppig (971896266@qq.com)
 /// @date    2018-06-05 05:21:11
 ///
 
#include <iostream>
#include <string>
#include <cstdio>
using std::cout;
using std::endl;
using std::string;


int main(){
	string s;
	s="Hello,world";
	string s1=s.substr(0,5);
	string s2=s.substr(5,100);
	cout<<" s1 = "<<s1<<"\t"<<"s1.size()="<<s1.size()<<endl
		<<" s2 = "<<s2<<"\t"<<"s2.lenth()="<<s2.length()<<endl <<endl;
	s1=s1.append(s2);
	cout <<"after append s1="<<s1<<endl;
	const char * ps=s.c_str();
	puts(ps);
	ps=s.data();
	cout<<"after s.data() my ps value:";
	puts(ps);
	cout<<"below is for loop"<<endl;
	cout<<"g++ string.c -std=c++11"<<endl;
	for(const auto &val:s){
		cout<<val;
	}
	cout<<endl;
	return 0;
}
