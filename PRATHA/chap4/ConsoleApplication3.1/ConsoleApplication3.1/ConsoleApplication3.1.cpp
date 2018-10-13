// ConsoleApplication3.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	const int SIZE = 15;
	cout << "What is your first name? ";
	char f_name[SIZE];
	cin.getline(f_name, SIZE);
	cout << "What is your last name? ";
	char l_name[SIZE];
	cin.getline(l_name, SIZE);
	cout << "What letter grade do you deserve ? ";
	char grade;
	cin >> grade;
	cout << "What is your age? ";
	int age;
	cin >> age;
	cout << "Name: " << l_name << ", " << f_name << endl;
	cout << "Grade: " << char(int(grade) + 1 )<<endl;
	cout << "Age: " << age << endl;
	return 0;
}

