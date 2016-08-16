// Ch7Functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "functions.h"
using namespace std;
int foo()
{
	return 5;
}

int goo()
{
	return 6;
}
int main()
{
	cout << "Question 1\n";
	cout << "Enter a number: ";
	int input;
	cin >> input; 

	cout << sumTo(input) << "\n";

	// function pointer 
	// example: int (*fctpntr)() : fctpntr is a pointer that points to a function that returns a integer
	int(*fcnPtr)() = foo; // fcnPtr points to function foo
	fcnPtr = goo; // fcnPtr now points to function goo REMEMBER YOU WANT THE ADDRESS NOT THE RETURN VALUE OR CALL

    return 0;
}

