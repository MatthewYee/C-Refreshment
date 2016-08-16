// Ch6Reference.cpp : Defines the entry point for the console application.
//

// This is reference

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Something
{
	int value1;
	float value2;
};

struct Other
{
	Something something;
	int otherValue;
};

Other other;

int main()
{
	int &ref = other.something.value1;
	// ref can now be used in place of other.something.value1
	other.something.value1 = 5;
	ref = 5;

    return 0;
}

