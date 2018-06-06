///
/// @file    class.c
/// @author  ppppppppig (971896266@qq.com)
/// @date    2018-06-05 23:41:26
///

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class Person{
	public:
	Person()
	:_price(0)
	,_band("MaXiaoNiubility")
	{
		cout << "Person" << endl;
	}
		void *setPrice(const float &p);
		void *setBand(const string &);
		bool operator << (const ofstream &of) const;
	private:
		float _price;
		string _band;
};


inline
void *Person::setPrice(const float &p){
	cout<<"setPrice"<<endl;
	_price = p;
	return NULL;
}//end of Person::setPrice

inline
void *Person::setBand(const string &s){
	cout << "setBand" << endl;
	_band=s;
	return NULL;
}//end of Person::setBand

int main(){
	Person per;
	per.setPrice(1.25);
	per.setBand("lenove");
	return 0;
}
