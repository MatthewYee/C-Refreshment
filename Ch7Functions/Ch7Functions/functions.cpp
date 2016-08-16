// defining functions 

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

/*
A function named sumTo() that takes an integer parameter 
and returns the sum of all the numbers between 1 and 
the input number.
*/

int sumTo(int input)
{
	// Initialize the total variable
	int total = 0; 

	// index from 0 to the beginning and add to total
	for (int inc = 0; inc <= input; inc++)
	{
		total += inc;
	}
	return total;
}
struct Employee
{
	string name;
};

void printEmployeeName(const Employee &employee)


