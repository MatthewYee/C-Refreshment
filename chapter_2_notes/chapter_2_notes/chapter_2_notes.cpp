// chapter_2_notes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
/*----------------VARIABLES------------------------------*/
	bool bValue;
	char chValue;	
	int nValue(5);	// direct initialization vs copy initialization
	float fValue;
	double dValue;

	cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl;
	cout << "char:\t\t" << sizeof(char) << " bytes" << endl;
	cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;
	cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << endl; // C++11, may not be supported by your compiler
	cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << endl; // C++11, may not be supported by your compiler
	cout << "short:\t\t" << sizeof(short) << " bytes" << endl;
	cout << "int:\t\t" << sizeof(int) << " bytes" << endl;
	cout << "long:\t\t" << sizeof(long) << " bytes" << endl;
	cout << "long long:\t" << sizeof(long long) << " bytes" << endl; // C++11, may not be supported by your compiler
	cout << "float:\t\t" << sizeof(float) << " bytes" << endl;
	cout << "double:\t\t" << sizeof(double) << " bytes" << endl;
	cout << "long double:\t" << sizeof(long double) << " bytes" << endl;


/*-----------------STRINGS------------------------------------*/
	// Character variable type produce only character
	char ch(97);	// initializing character
	cout << ch;		// cout prints a character 

	// integers as characters the lazy way
	int i(ch);		// assign the value of ch to an integer
	cout << i;		// print the integer value

	// integers as characters : better way; type cast
	// syntax : static_cast<new_type> (expression)
	cout << ch << endl;
	cout << static_cast<int>(ch) << endl;
	cout << ch << endl;

/*------------------------Literals-------------------------*/
	// two kinds of constants literal and symbolic
	
	  /* literal constants are literal numbers inserted in the code. Can't change their number */
	
	bool myNameISAlex = true;	// true is a boolean literal constant
	int x = 5;					// 5 is an integer literal constan

	  /* how to make floating point literals */
	double pi = 3.14159;		// a double literal
	double avogadro = 6.02e23	// 

    return 0;
}

