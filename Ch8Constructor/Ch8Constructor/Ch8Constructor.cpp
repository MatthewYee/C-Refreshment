// Ch8Constructor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

class Ball 
{
	// default values private
	string m_color = "Black";
	double m_radius = 10;

public: 

	Ball(double radius)
	{
		m_color = "black";
		m_radius = radius;
	}

	Ball(const string &color = "black", double radius = 10.0)			// Incorrect Ball(string color = "black", double radius = 10)
	{
		m_color = color;
		m_radius = radius;
	}

	void print()
	{
		cout << "color: " << m_color << ", radius: " << m_radius << '\n';
	}
	
};

class RGBA
{
	// private variables
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;

public:
	RGBA(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0 , uint8_t alpha = 255) : m_red(red), m_blue(blue), m_green(green), m_alpha(alpha)
	{
		// all done when used
	}

	void print()
	{
		//  you have to cast/convert the uint8_t variable to a int
		cout << "r=" << static_cast<int>(m_red) << ' ' << "g=" << static_cast<int>(m_green) << ' ' << "b=" << static_cast<int>(m_blue) << ' ' << "a=" << static_cast<int>(m_alpha) << '\n';
	}
};


int main()
{
	Ball def;
	def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty("blue", 20.0);
	blueTwenty.print();

	// Chapter 8.5 a quiz test 
	RGBA teal(0, 127, 127);
	teal.print();

    return 0;
}

