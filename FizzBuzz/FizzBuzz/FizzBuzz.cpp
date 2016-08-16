// FizzBuzz.cpp : Defines the entry point for the console application.
//this programs prints number 1 - 100 that is multiples of three but not multiples of five 

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	int i;											// increment value
	for (i = 0; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0 )
		{
			cout << "FizzBuzz " << i << endl;
		}
		else if (i % 3 == 0)
		{
			cout << "Fizz " << i << endl;
		}
		else if (i % 5 == 0)
		{
			cout << "Buzz " << i << endl;
		}

	}

    return 0;
}

