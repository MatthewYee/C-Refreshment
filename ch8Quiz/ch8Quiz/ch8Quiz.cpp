// ch8Quiz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std; 

class Point3d
{
private:
	double m_x, m_y, m_z;

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{

	}

	void print()
	{
		std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}

	void moveByVector(Vector3d &v)
	{
		// implement this function as a friend of class Vector3d
	}
	void moveByVector(Vector3d &v); // so we can use Vector3d here
									// note: we can't define this function here, because Vector3d hasn't been declared yet (just forward declared)
};

class Vector3d
{
private:
	double m_x, m_y, m_z;

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{

	}
	void print()
	{
		cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
	}
	//friend class Point3d;					// 1a make Point3d a friend class of Vector3d
	//friend clas Point3d::moveByVector; (Incorrect, I thought this would be better however check section Friend Member functions from 8.13)		// 1b instead of 1a or make member function Point3d::moveByVector to be a friend of Vector3d
	// for 1b you need to change the order for forward declaration 
	friend void Point3d::moveByVector(Vector3d &v);

};

void Point3d::moveByVector(Vector3d &v) // have to add the function wher it updates the current vector
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}

int main()
{
	Point3d p(1.0, 2.0, 3.0);
	Vector3d v(2.0, 2.0, -3.0);

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}
