// Ch6SortinganArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	const int size = 5;
	int array[size] = { 30, 50, 20, 10, 40 };

	for (int startIndex = 0; startIndex < size; ++startIndex)
	{
		// instead of smallest go for the largest index
		int largestIndex = startIndex;

		// Look for largest element remaing in the array (starting at startIndex+ 
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			// if the current element is larger than our previously found largest 
			if (array[currentIndex] > array[largestIndex])
				// This is the largest number for this iteration
				largestIndex = currentIndex;
		}

		// Swap our start element with our smallest element
		swap(array[startIndex], array[largestIndex]);

	}

	// Now print our sorted array as proof it works

	for (int index = 0; index < size; ++index)
	{
		cout << array[index] << ' ';
	}

    return 0;
}

