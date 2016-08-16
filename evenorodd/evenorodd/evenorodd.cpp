// evenorodd.cpp : Defines the entry point for the console application.
// this program is the number even or odd

#include "stdafx.h"
#include <iostream>

int getNumber()
{
	using namespace std;
	cout << "Enter a number: ";
	int x;
	cin >> x;
	return x;
}

void evensorodds(int x)
{
	using namespace std;
	if (x % 2 == 0)
	{
		cout << x << "is even" << endl;
	}
	else
	{
		cout << x << " is odd" << endl;
	}
}

int main()
{
	int num;
	num = getNumber();
	evensorodds(num);
    return 0;
}

