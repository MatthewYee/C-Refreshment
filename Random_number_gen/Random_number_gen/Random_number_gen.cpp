// Random_number_gen.cpp : Defines the entry point for the console application.
// Computer can never toss a coin or a die so it needs to simulate randomness 

#include "stdafx.h"
#include <iostream>
#include <cstdlib>			// for rand() and srand() 
#include <ctime>			// for time
using namespace std;

int main()
{
	// currently this program prints the same number and is predictable to change that we add time

	//srand(5323); // set initial seed number
	
	srand(static_cast<unsigned int>(time(0)));

	// Print 100 numbers
	for (int count = 0; count < 100; count++)
	{
		cout << rand() << "\t";

		// If we've printed 5 numbers, start a new row
		if ((count + 1) % 5 == 0)
		{
			std::cout << "\n";
		}
	}
    return 0;
}

