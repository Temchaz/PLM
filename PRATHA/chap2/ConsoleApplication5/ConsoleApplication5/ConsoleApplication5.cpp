// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

double ast_un(double a) {
	return a * 63240;
}

int main()
{
	using namespace std;
	cout << "Enter the number of light years: ";
	double light_years;
	cin >> light_years;
	cout << light_years << " light years = " << ast_un(light_years) << " astronomical units." << endl;
	return 0;
}

