// Ch8PublicandPrivateClass.cpp : Defines the entry point for the console application.
// will be doing a quiz for 

#include "stdafx.h"
#include <iostream> 

using namespace std;

// number 2 of chapter 8 quiz
class Point3d 
{
	double m_x;			// x-axis variable
	double m_y;			// y-axis variable
	double m_z;			// z-axis variable

public:
	void setValues(double x, double y, double z)		// setValues set x,y, and z axis variable 
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}
	void printcoordinate()
	{
		cout << "< " << m_x << " , " << m_y << " , " << m_z << " >" << '\n';
	}

};

// number 3 question stack and heap
class Stack
{
	// private members are values public members are function
	int stackarray[10];				// Create array of 10 
	int lenIndex = 0;				// lenindex keep track of the stack length 
									// so we start with an empty stack 

public: 
	bool push(int inputnumber)
	{
		// check the stack if it is full if it is then don't add
		if (lenIndex == 9)				// remember arrays start from 0 to target number - 1 
		{
			cout << "Can't add, for stack is full\n";
			return false;
		}
		else
		{
			stackarray[lenIndex] = inputnumber;
			++lenIndex;
			return true;
		}
	}

	void reset()
	{
		// set length to 0 and all element values to 0
		lenIndex = 0;
		stackarray[10]= {};
	}
	int pop()
	{
		// this pop of the value off the top of the stack however we must first check if the stack is empty 
		if (lenIndex == 0)
		{
			cout << "stack is already empty you can't pop anymore\n";
			return -1;
		}
		else
		{
			// I wonder why returning stackarray[10] = { } does not eliminate it
			cout << "popping stack\n";
			return stackarray[--lenIndex];		// set the element to 0 since we are popping the stack
		}
	}

	void print()
	{
		cout << "(";
		for (int i = 0; i < lenIndex; i++)
		{
			cout << " " << stackarray[i] << " ";
		}
		cout << ")\n";
	}
};

int main()
{
	/* quiz number 2
	Point3d coordinates;
	coordinates.setValues(35, 45.7, 12.20);
	coordinates.printcoordinate();
	*/

	Stack stack;
	stack.reset();
	stack.print();
	
	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

    return 0;
}

