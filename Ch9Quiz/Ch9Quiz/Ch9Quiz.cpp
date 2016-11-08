// Ch9Quiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdint>                  // For the int32_t type variable
#include <cassert>					// for assert

using namespace std;

/*class Point						// Assuming Point is a class and point is an instance of that class, should you use a normal/friend or member function overload for the following operators
{
private:

public:

};

1a) point + point       : make it a normal/friend function since you are taking two different objects and adding them together: Correct Binary operator+ is best implemented
1b) -point              : make it a member function : Correct operator- is best implemented as a member function
1c) std::cout << point  : member function since it left bitwise operator wrong : operator<< must be implemented as a normal/friend function.
1d) point = 5;          : member function since it is an assignment operator : correct

*/

/* Write a class named Average 
- It keeps track of the average of all integers passed to it
- used two members: 1) a type int32_t to keep track of the sum of all the numbers seen so far 
                    2) a type int8_t to keep track of how many numbers you've seen so far 
*/

class Average
{
private:
	int8_t m_amountOfNum = 0;       // Tracks the amount of number we have seen. Direct initiliazation  for now I have to use the copy initialization 
	int32_t m_sumOfNum = 0;		    // Sum all the number that we come across

public:
	Average()
	{ }

	friend ostream& operator<<(ostream &out, const Average &average)
	{ // REVIEW THE OVERLOADING OUTPUT OPERATOR 
		// Our average is the sum of the numbers we've seen divided by the count of the numbers we've seen
		// We need to remember to do a floating point division here, not an integer division

		// cast the number to be from int32_t or whatever variable type to the desired one
		out << static_cast<double>(average.m_sumOfNum) / average.m_amountOfNum;

		return out;
	}

	// Overloading operator +=, therefore it would be done as a member function: Right definition but wrong method
	Average& operator+=(int num)
	{
		// basically update the objects data
		m_sumOfNum += num;
		++m_amountOfNum; 

		// return the updated object
		return *this;
	}
};

class IntArray
{
private:
	int m_length = 0;
	int *m_array = nullptr;				// 

public: 
	IntArray(int length):m_length(length)
	{
		assert(length > 0 && "IntArray length should be a positive integer");

		m_array = new int[m_length] { 0 };
	}

	// Copy Constructor that does a deep copy
	IntArray(const IntArray &array) :m_length(array.m_length) 
	{
		// allocate new array
		m_array = new int[m_length];

		// Copy elements from original array to new array
		for (int count = 0; count < array.m_length; ++count)
		{
			m_array[count] = array.m_array[count];
		}
	}

	// Deallocate memory
	~IntArray()
	{
		delete[] m_array;
	}

	// If the values you are getting is off then the copy constructor is not properly implemented 

	friend ostream& operator<<(ostream &out, const IntArray &array)
	{
		out << array.m_length[count] << ' '; 
	}

	int& operator[] (const int index)
	{
		assert(index >= 0);
		assert(index < m_length);
		return m_array[index];
	}

	IntArray& operator= (const IntArray &array)
	{
		// self assignment guard
		if (this == &array)
			return *this;

		// If this array already exists, delete it so we don't leak memory
		delete[] m_array;

		// allocate a new array
		m_length = array.m_length;

		// Copy elements from original array to new array
		for (int count = 0; count < array.m_length; ++count)
			m_array[count] = array.m_array[count];
		
		return *this;
	}

};

IntArray fillArray()
{

	IntArray a(5);
	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	Average avg;

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';
    return 0;
}

