#include "stdafx.h"
#include <iostream>
#include "ch2p4.h"
double getHeight()
{
	using namespace std;
	cout << "Enter the initial height of the tower in meters: ";
	double height;
	cin >> height;
	return height;
}


double calculateHeight(double height, int time)
{
	using namespace std;
	double distanceFallen = (constants::my_gravity * time * time) / 2;
	double currentHeight = height - distanceFallen;
	return currentHeight;
}

void printHeight(double height, int time)
{
	using namespace std;
	if (height > 0.0)
	{
		cout << "At " << time << " seconds, the ball is at height: " << height << " meters\n";
	}
	else
	{
		cout << "At " << time << " seconds, the ball is on the ground\n";
	}
}

void calculateAndPrintHeight(double height, int time)
{
	double cheight = calculateHeight(height, time);
	printHeight(cheight, time);
}

