#pragma once
#ifndef POINT3D_H
#define POINT3D_H

// forward declaration
class Vector3d; // You missed this. I suspect this to be wrong as I have to bring the scope of other files
				//Forward declaration for class Vector3d for function moveByVector()

class Point3d
{
private:
	double m_x, m_y, m_z;

public:
	Point3d(double x = 0.0, double y = 0.0, double z = 0.0)
		: m_x(x), m_y(y), m_z(z)
	{

	}
	// you stop defining functions as well, these are forward declaration
	void print();
	void moveByVector(Vector3d &v); // so we can use Vector3d here
									// note: we can't define this function here, because Vector3d hasn't been declared yet (just forward declared)
};

#endif // POINT3D_H