// StructureofFunction.cpp : Defines the entry point for the console application.
//By Matthew Yee
// from LEARNCpp

#include "stdafx.h"
#include <iostream> //

int main()
{
	/* 
	 Most common statement
	*/
	int x; // integer variable / declaration statement
	x = 5; // initialize variable / assignment statement
	std::cout << x; // print statement / output statement 

	/* Programs can be */

	std::cout << "Hello World!";

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

    return 0;
}

