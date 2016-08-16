// Quiz chapter 2

#include "stdafx.h"
#include <iostream>
#include "ch2quiz.h"
int main()
{
	using namespace std; 
	double num1 = getDouble();
	char op = getOperator();
	double num2 = getDouble();
	printResult(num1, op, num2);
	return 0;
}
