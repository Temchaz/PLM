// ConsoleApplication2.3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
double three_in_one(double d, double m, double s) {
	return d + ((m + (s / 60)) / 60);
}

int main()
{
	using namespace std;
	cout << "Enter а lati tude in degrees, minute s, and seconds :" << endl;
	cout << "First, enter the degrees: ";
	double degree;
	cin >> degree;
	cout << "Next , enter the minutes of arc: ";
	double minut;
	cin >> minut;
	cout << "Finally, enter the seconds of arc: ";
	double sec;
	cin >> sec;
	cout << degree << " degrees, " << minut << " minutes, " 
		 << sec << " seconds = " << three_in_one(degree, minut, sec) 
		 << " degrees" << endl;
	return 0;
}

