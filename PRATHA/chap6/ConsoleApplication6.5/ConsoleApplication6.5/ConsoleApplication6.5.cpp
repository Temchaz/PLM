// ConsoleApplication6.5.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "¬ведите доход: ";
	double salary;
	double tax;
	while (cin >> salary && salary > 0) {
		if (salary <= 5000)
			tax = 0;
		else if (salary > 5000 && salary <= 15000)
			tax = (salary - 5000)*0.1;
		else if (salary > 15000 && salary <= 35000)
			tax = 10000 * 0.1 + (salary - 10000)*0.15;
		else tax = 10000 * 0.1 + 20000 * 0.15 + (salary - 35000)*0.2;
		cout << "налог составл€ет " << tax << " трапов" << endl;
	}
	
	return 0;
}

