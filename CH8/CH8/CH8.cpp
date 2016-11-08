// CH8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

/*
1a) Write a class named Point2d. Point2d should contain two member variables of type double: m_x, and m_y, both defaulted to 0.0. Provide a constructor and a print function.

The following program should run:

#include <iostream>

int main()
{
	Point2d first;
	Point2d second(3.0, 4.0);
	first.print();
	second.print();

	return 0;
}
This should print:

Point2d(0, 0);
Point2d(3, 4);
*/

class Point2d
{
private:
	double m_x;
	double m_y;

public:
	// make a constructor that initialize the variables
	Point2d(double x = 0.0, double y = 0.0):m_x(x), m_y(y)
	{ }

	// adding another member function distanceTo
	double distanceTo(Point2d other)             //class Point2d already made the 
	{
		return sqrt((m_x - other.m_x)*(m_x - other.m_x) + (m_y - other.m_y)*(m_y - other.m_y));
	}

	void print()
	{
		cout << "Point2d( " << m_x << " ," << m_y << " )" << "\n";
	}

	// make forward declaration for nonmember function
	friend double distanceFrom(Point2d x, Point2d y);
};

// creating a non-member friend function fromTo
double distanceFrom(Point2d x, Point2d y)		// remember not a member so it can't access private data
{
	return sqrt((x.m_x - y.m_x)*(x.m_x - y.m_x) + (x.m_y - y.m_y)*(x.m_y - y.m_y));
}


int main()
{
	Point2d first;
	Point2d second(3.0, 4.0);
	first.print();
	second.print();

	cout << "Distance between two points: " << first.distanceTo(second) << '\n';    //1b
	cout << "Distance between two points: " << distanceFrom(first, second) << '\n'; //1c 


    return 0;
}