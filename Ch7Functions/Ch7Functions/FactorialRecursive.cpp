/*
	This will be a factorial function program
*/

#include <iostream>

using namespace std; 

int factorial(int num)
{
	// the goal is to multiply from given number down to 1
	if (num <= 0)
		// won't consider negative number so I only postivie number and if we input 0! it equals 1
		return 1;
	else if (num <= 1)
		// we reach to the end of the factorial so terminate
		return 1;
	else
		// now we perform the recursive of factorial
		return num * factorial(num - 1);
}

int sumNumbers(int x)
{
	if (x < 10)
		return x;
	else
		return sumNumbers(x / 10) + x % 10;
}

int main()
{
	// perform factorial recursive
	cout << factorial(5) << ' ';
}