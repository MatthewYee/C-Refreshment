// Ch7_13_commandline.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	cout << "There are " << argc << " arguments:\n";

	// Loop through each argument and print its number and value
	for (int count = 0; count < argc; ++count)
		cout << count << " " << argv[count] << '\n';

    return 0;
}

