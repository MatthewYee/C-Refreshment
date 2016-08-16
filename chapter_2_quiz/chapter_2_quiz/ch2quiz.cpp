#include "stdafx.h"
#include <iostream>

double getDouble()
{
	using namespace std;
	cout << "Enter a double value: ";
	double x;
	cin >> x;
	return x;
}
char getOperator()
{
	using namespace std;
	cout << "Enter a operator: ";
	char op;
	cin >> op;
	return op;
}

void printResult(double x, char op, double y)
{	
	using namespace std;

	if (op == '+')
		cout << x << " " << op << " " << y << " is " << x + y << endl;

	else if (op == '-')
		cout << x << " " << op << " " << y << " is " << x - y << endl;

	else if (op == '*')
		cout << x << " " << op << " " << y << " is " << x * y << endl;

	else if (op == '/')
		cout << x << " " << op << " " << y << " is " << x / y << endl;

	else
		cout << "Not valid try again";
}