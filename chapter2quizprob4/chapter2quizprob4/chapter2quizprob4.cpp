// chapter2quizprob4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "ch2p4.h"

// function define 



int main()
{
	using namespace std;
	const double height = getHeight();

	calculateAndPrintHeight(height, 0);
	calculateAndPrintHeight(height, 1);
	calculateAndPrintHeight(height, 2);
	calculateAndPrintHeight(height, 3);
	calculateAndPrintHeight(height, 4);
	calculateAndPrintHeight(height, 5);
	
    return 0;
}

