// ch6notes.cpp : Defines the entry point for the console application.
// Arrays

#include "stdafx.h"
#include <iostream>
using namespace std;

void passValue(int value) // value is a copy of the argument
{
	value = 99; // so changing it here won't change the value of the argument
}

void passArray(int prime[5]) // prime is the actual array
{
	prime[0] = 11; // so changing it here will change the original argument!
	prime[1] = 7;
	prime[2] = 5;
	prime[3] = 3;
	prime[4] = 2;
}
enum StudentNames
{
	KENNY,									// 0
	KYLE,									// 1
	STAN,									// 2
	BUTTERS,								// 3
	CARTMAN,								// 4
	MAX_STUDENTS							// 5
};


int main()
{
	// fast ways to initialize arrays
	int prime[5] = { 2,3,5,7,11 };			// hold the first 5 primes
	int array[] = { 0, 1, 2, 3, 4 };		// let initializer list set size of the array
	
	cout << prime[4] << '\n';
	cout << array[4] << '\n';

	// Problems with arrays is that integers indices do not provide any information to the programmer
	const int numberOfStudents(5);
	int testScores[numberOfStudents];
	testScores[2] = 76;						// Who is represented by array element number 2

	// Solution to arrays representation using Enumeration
	int scores[MAX_STUDENTS]; 
	scores[STAN] = 76; 

	// if it is enum class then casting is the solution to solving it static_cast<int>(enum class) 
	// however this is not the efficient so you put enum class in a namespace just like 

	

	// passing arrays to functions 
	// C++ treats arrays differently since the size can be large C++ pass the arrays directly instead of the copy which is how C++ treat variables.
	int value = 1;
	std::cout << "before passValue: " << value << "\n";
	passValue(value);
	std::cout << "after passValue: " << value << "\n";

	int prime[5] = { 2, 3, 5, 7, 11 };
	std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << "\n";
	passArray(prime);
	std::cout << "after passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << "\n";

    return 0;
}

