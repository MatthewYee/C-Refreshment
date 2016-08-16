// Matthew Yee
// 

#include <iostream>

using namespace std;

// lets begin with function pointer

/*
 QUIZ 1
*/


char get_operator()
{
	char mathop;
	do
	{
		cout << "Enter an Operation ('+', '-', '*', '/'): ";
		cin >> mathop;

	} while (mathop != '+' && mathop != '-' && mathop != '*' && mathop != '/');
	return mathop;
}

int add(int num1, int num2)
{
	return num1 + num2;
}

int subtract(int num1, int num2)
{
	return num1 - num2;
}

int multiply(int num1, int num2)
{
	return num1 * num2;
}

int divide(int num1, int num2)
{
	return num1 / num2;
}

typedef int(*arithmeticFcn)(int, int);

struct arithmeticStruct
{
	char op;				// math operator 
	arithmeticFcn func;		//function poinnter
};

// setting up arithmetic struc array 
static arithmeticStruct arithmeticArray[]
{
	{ '+', add },
	{ '-', subtract },
	{ '*', multiply },
	{ '/', divide }
};


int get_integer()
{
	int num;
	// prompt user for first integer 
	cout << "Enter first integer: ";
	cin >> num;
	return num;
}
arithmeticFcn getArithmeticFunction(char op)  // so I have to create it as a 
{
	for (auto &arith : arithmeticArray)
	{
		if (arith.op == op)
			return arith.fcn;
	}

	return add; // default will be to add
}

int main()
{
	int num1, num2;
	char op;
	num1 = get_integer();
	op = get_operator();
	num2 = get_integer();
	arithmeticFcn result = getArithmeticFunction(op);
	cout << num1 << ' ' << op << ' ' << num2 << result(num1, num2) << '\n';

	return 0;
}