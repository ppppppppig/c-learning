///
/// @file    io1.cc
/// @author  ppppppppig (971896266@qq.com)
/// @date    2018-06-08 01:08:03
///
#include <iostream>
#include <string>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::string;


//goodbit  有效状态
//badbit   系统级别的故障，无法恢复
//failbit  可以恢复的错误
//eofbit   到达了当前流的末尾

void printCin()
{
	cout << "cin's goodbit = " << cin.good() << endl;	
	cout << "cin's badbit = " << cin.bad() << endl;
	cout << "cin's failbit = " << cin.fail() << endl;
	cout << "cin's eofbit = " << cin.eof() << endl;
}

void test0(void)
{
	cout << "sizeof(cout) = " << sizeof(cout) << endl;
	cout << "sizeof(cin) = " << sizeof(cin) << endl;

	printCin();
	int number = 0;
	while(cin) { // 判断流的状态是不是有效状态
		cin >> number;
		cout << "number = " << number << endl;
	}
	cout << endl;
	printCin();
	cout << endl;

	cin.clear();//重置流的状态
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');			//清空缓冲区
	printCin();

	string str;
	cin >> str;//把空格作为分隔符
	cout << "str = " << str;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');			//清空缓冲区

	//char buff[1024];
	string line;
	while(std::getline(cin, line)) //从终端获取一行字符串
	{
		cout << "line = " << line << endl;
	}
}

void test1()
{
	int number;
	cout << ">> pls input a integer number:";
	while(cin >> number, !cin.eof())
	{
		if(cin.bad()) {
			cout << "stream has corrupted!" << endl;
			return;
		} else if (cin.fail()) {
			cin.clear();
		}
	}
}
				void test1(void)
				{.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << ">> pls input a integer number:";
					continue;
				}
			cout << "number = " << number << endl;
		}
	}
}

int main(void)
{
	//test0();
	test1();

	return 0;
}

