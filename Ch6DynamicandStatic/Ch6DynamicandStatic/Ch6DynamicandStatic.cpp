// Ch6DynamicandStatic.cpp : Defines the entry point for the console application.
//

// We will be looking into dynamic and static array constant 

/*
 - Static memory allocation happens for static and global variables. 
   Memory for these types of variables is allocated once when your program is run and persists throughout the life of your program.

 - Automatic memory allocation happens for function parameters and local variables. 
   Memory for these types of variables is allocated when the relevant block is entered, and freed when the block is exited, as many times as necessary.

 - Dynamic memory allocation is the topic of this article.
	A heap gives extra memory to accomodate more memory 
	new int; // dynamically allocate an integer (and discard the result)
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std; 

void sortArray(string *array, int length)  // deter the array
{
	// Step through each element of the array
	for (int startIndex = 0; startIndex < length; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we've encountered so far.
		int smallestIndex = startIndex;

		// Look for smallest element remaining in the array (starting at startIndex+1)
		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			// If the current element is smaller than our previously found smallest
			if (array[currentIndex] < array[smallestIndex])
				// This is the new smallest number for this iteration
				smallestIndex = currentIndex;
		}

		// Swap our start element with our smallest element
		swap(array[startIndex], array[smallestIndex]);
	}
}

int main()
{
	// creating new dynamic allocated variable
	//int *ptr = new int(5);
	//int *ptr2 = new int{ 6 };

	// assume ptr has previously been allocated with operator new
	//delete ptr;			// return the memory pointed to by ptr to the operating system 
	//ptr = 0;			// set to be a null pointer (use nullptr instead of 0 in C+11) BE SURE TO SET ALL NUlL POINTER OTHER WISE YOU GET DANGLING ONES 

	// ALternative way to handle possible crash of memory allocation
	//int *value = new(nothrow)int;			// THis will return failed allocate memory to null 

	// Write a program that 
	/*
	  Asks the user how many names they wish to enter 
	  Asks the user to enter each name
	  Calls a function to sort the names 
	  Prints the sorted list of names
	*/
	cout << "How many names would you like to enter? ";
	int length;
	cin >> length;

	// Allocate an array to hold the names
	std::string *names = new std::string[length];

	// Ask user to enter all the names
	for (auto i = 0; i < length; ++i)
	{
		cout << "Enter name #" << i + 1 << ": ";
		cin >> names[i];
	}

	// Sort the array
	sortArray(names, length);

	cout << "\nHere is your sorted list:\n";
	// Print the sorted array
	for (auto i = 0; i < length; ++i)
		cout << "Name #" << i + 1 << ": " << names[i] << '\n';

	delete[] names; // don't forget to use array delete
	names = nullptr; // use 0 if not C++11

    return 0;
}

