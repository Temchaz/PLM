// ConsoleApplication2.5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

double consumption(double d, double p) {
	return p / d;
}
int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	cout << "введите пройденное расстояние в километрах: ";
	int distance;
	cin >> distance;
	cout << "введите кол-во литров израсходонного бензина: ";
	int petrol;
	cin >> petrol;
	cout << "на 1 километр вам понадобилось: " << consumption(distance, petrol) << " литров бензина" << endl;
	return 0;
}

