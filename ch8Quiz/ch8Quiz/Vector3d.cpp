#include "stdafx.h"
#include <iostream>
#include "Vector3d.h"

using namespace std;

void Vector3d::print()
{
	std::cout << "Vector(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}