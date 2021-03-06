#pragma once
#ifndef VECTOR3D_H
#define VECTOR3D_H

// insert library to get functions from point3d
#include "Point3d.h"

class Vector3d
{
private:
	double m_x;
	double m_y;
	double m_z;

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z) 
	{}

	void print();
	friend void Point3d::moveByVector(Vector3d&);
};
#endif // !VECTOR3D_H