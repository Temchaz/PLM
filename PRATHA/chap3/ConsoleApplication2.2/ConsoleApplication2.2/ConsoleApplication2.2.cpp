// ConsoleApplication2.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

double height(double f, double i) {
	return (f * 12 + i)*0.0254;
}

double weight(double w) {
	return w / 2.2;
}

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	cout << "введите кол-во футов в вашем росте: ";
	double ft;
	cin >> ft;
	cout << "введите кол-во дюймов в вашем росте: ";
	double inch;
	cin >> inch;
	cout << "введите кол-во фунтов в вашем весе:";
	double wft;
	cin >> wft;
	double bmi = weight(wft) / pow(height(ft, inch), 2);
	cout <<"индекс массы тела: "<< bmi << endl;
	return 0;
}

