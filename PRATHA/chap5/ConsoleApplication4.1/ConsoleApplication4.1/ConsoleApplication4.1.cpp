// ConsoleApplication4.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	cout << "введите первое значение: ";
	int first_value;
	cin >> first_value;
	cout << "введите второе значение: ";
	int second_value;
	cin >> second_value;
	int sum = first_value + second_value;
	for (int i = 1; i<second_value - first_value; i++)
		sum += first_value + i;
	cout << "сумма всех целых чисел от "
		<< first_value
		<< " до "
		<< second_value
		<< " равна "
		<< sum << endl;
	return 0;
}

