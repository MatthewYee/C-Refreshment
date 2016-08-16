// Ch6pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	// We will be going over scaling which if we use a 4 byte pointer we have 4 pointers pointing toward the first
	// four array elements in an array

	int value = 7;
	int *ptr = &value;

	std::cout << ptr << '\n';
	std::cout << ptr + 1 << '\n';
	std::cout << ptr + 2 << '\n';
	std::cout << ptr + 3 << '\n';

	// The following will print the address by difference of 2 since the 


	short value = 7;
	short *ptr = &value;

	std::cout << ptr << '\n';
	std::cout << ptr + 1 << '\n';
	std::cout << ptr + 2 << '\n';
	std::cout << ptr + 3 << '\n';


    return 0;
}

