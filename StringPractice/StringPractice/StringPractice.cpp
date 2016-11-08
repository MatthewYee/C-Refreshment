// StringPractice.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
	int i = 4;
	double d = 4.0;
	string s = "HackerRank ";

	// Declare second integer, double, and String variables.
	int i2;
	double d2;
	string s2;
	// Read and save an integer, double, and String to your variables.
	//cout << "Enter a second integer ";
	cin >> i2;

	//cout << "Enter a second double ";
	cin >> d2;

	// cout << "Finish a sentence starting with HackerRank ";
	

	// Print the sum of both integer variables on a new line.

	cout << i + i2 << '\n';

	// Print the sum of the double variables on a new line.

	cout << d + d2 << '\n';

	// Concatenate and print the String variables on a new line

	cout << << '\n';

	// The 's' variable above should be printed first.

	return 0;

}

