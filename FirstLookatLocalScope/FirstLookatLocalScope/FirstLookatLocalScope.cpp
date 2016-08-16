// FirstLookatLocalScope.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

/*
  Scope determines who can see and use the variable during the time it is instantiated
  BOTH FUNCTIONS parameters and variables declared inside the function bpdy have local scope. 

*/

int add(int x, int y)
{
	return x + y;
}

int main()
{
	using namespace std;
	int x = 5;
	int y = 6;
	cout << add(x, y) << endl;



    return 0;
}

