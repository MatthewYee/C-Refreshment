#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// prototype 
int sumTo(int input);

struct Employee
{
	string name;
};

void printEmployeeName(const Employee &employee);

void minmax(int one, int two, int &minout, int &maxout);

const int& getElement(const int *arrays, int index)
#endif //FUNCTIONS_H