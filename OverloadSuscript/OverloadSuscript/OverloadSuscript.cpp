// OverloadSuscript.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std; 

struct StudentGrade
{
	string name;
	char grade;
};

class GradeMap
{
private:
	vector<StudentGrade> m_map;

public:
	char& operator[](const string &name);

	GradeMap()
	{
	}
};

char& GradeMap::operator[](const std::string &name)
{
	// See if we can find the name in the vector
	for (auto &ref : m_map)
	{
		// If we found the name in the vector, return the grade
		if (ref.name == name)
			return ref.grade;
	}

	// otherwise create a new StudentGrade for this student
	StudentGrade temp{ name, ' ' };

	// otherwise add this to the end of our vector
	m_map.push_back(temp);

	// and return the element
	return m_map.back().grade;
}

int main()
{
	GradeMap grades;
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}

