// overloadingtypecast.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Mystring 
{
private: 
	string m_string;
public:
	Mystring(const string string=""):m_string(string)
	{
	}
	string operator()(int index1, int length) // correction char operator()(string input) 
	{
		string ret;
		for (int count = 0; count < length; ++count)
			ret += m_string[index1 + count];
		return ret;
	}

};

int main()
{
	Mystring string("Hello, world!");
	cout << string(7, 5); // start at index 7 and return 5 characters

	return 0;
}

