// ConsoleApplication4.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	int number;
	int sum = 0;
	do {
		cout << "введите число: ";
		cin >> number;
		sum += number;
	} while (number);
	cout << "накопленная сумма равна: " << sum << endl;
	return 0;
}

