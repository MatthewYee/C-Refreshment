// ch6arrayquiz.cpp : Defines the entry point for the console application.
//

/*
Declare an array to hold the high temperature (to the nearest tenth of a degree) for each day of a year (assume 365 days in a year). 
Initialize the array with a value of 0.0 for each day.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

namespace Animals {

	enum Animals
	{
		/*Set up an enum with the names of the following animals: chicken, dog, cat, elephant, duck, and snake.
		Put the enum in a namespace. Define an array with an element for each of these animals, and use an initializer
		list to initialize each element to hold the number of legs that animal has.
		Write a main function that prints the number of legs an elephant has, using the enumerator.*/

		CHICKEN,
		DOG,
		CAT,
		ELEPHANT,
		DUCK,
		SNAKE,
		MAX_ANIMALS


	};

}

int main()
{
	
	double temperature[365] = {0.0};	// initialize all 365 days to be 

	int animal[Animals::MAX_ANIMALS];
	

    return 0;
}

