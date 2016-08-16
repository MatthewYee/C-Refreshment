#pragma once
#ifndef CH2P4_H
#define CH2P4_H

namespace constants
{
	const double my_gravity(9.8); // m/s^2 -- gravity is light on this planet 
}

double getHeight();
double calculateHeight(double height, int time);
void printHeight(double height, int time);
void calculateAndPrintHeight(double x, int time);



#endif // CH2P4_H