// DSA_Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

void getName(std::string* name)
{
	std::cout << "Enter a name for the student: ";
	std::cin >> *name;
	std::cout << "\n";
}

void getGrade(double* grade)
{
	std::cout << "Enter a grade: ";
	std::cin >> *grade;

	while (*grade < 0 || *grade > 100)
	{
		std::cout << "Sorry, the grade must be between 0-100. Please enter a new grade.\n";
		std::cout << "Enter a grade: ";
		std::cin >> *grade;
	}
	
	std::cout << "\n";
}

double averageGrade(double** grades, int length)
{
	double totalGrades = 0.0;
	for (int i = 0; i < length; ++i)
	{
		totalGrades += *(grades[i]);
	}

	return totalGrades/static_cast<double>(length);
}

int main()
{
    std::cout << "Hello World! This is lab #1!\n";

	std::string studentName;
	getName(&studentName);
	std::cout << "The student's name is: " << studentName << "!\n";

	double grade1 = 0;
	double grade2 = 0;
	double grade3 = 0;
	getGrade(&grade1);
	getGrade(&grade2);
	getGrade(&grade3);

	const int gradeListLength = 3;
	double* gradeList[gradeListLength];
	gradeList[0] = &grade1;
	gradeList[1] = &grade2;
	gradeList[2] = &grade3;

	double avgGrade = averageGrade(gradeList, gradeListLength);

	std::cout << "The average grade for " << studentName << " is " << avgGrade << ".\n";
	
	return 0;
}

