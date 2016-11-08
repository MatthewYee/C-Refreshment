#include"stdafx.h"
#include <iostream>
#include"Point3d.h"
#include "Vector3d.h"
using namespace std;




void Point3d::moveByVector(Vector3d &v) // have to add the function wher it updates the current vector
{
	m_x += v.m_x;
	m_y += v.m_y;
	m_z += v.m_z;
}

void Point3d::print()
{
	std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}