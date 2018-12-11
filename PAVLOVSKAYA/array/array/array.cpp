// array.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	cout << "введите длину массива: ";
	int n;
	cin >> n;
	double* arr = new double[n];
	for (int i=0; i < n; i++) {
		cout << "введите " << i + 1 << " элемент: ";
		cin >> arr[i];
	}
	double max_abs=0;
	for (int i=0; i < n; i++) {
		if (abs(arr[i]) > abs(max_abs))
			max_abs = arr[i];
	}
	cout << "максимальный по модулю элемент масиива: "
		 << max_abs << endl << endl;
	double sum = 0;
	bool state=0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0 && state == 0)
			state = 1;
		else if (state == 1 && arr[i] <= 0)
			sum += arr[i];
		else if (state == 1 && arr[i] > 0)
			break;
	}
	cout << "сумма элементов массива между первым и вторым " << endl
		 << "положительными элементами: " << sum << endl << endl;

	int t;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1; j++)
			if (arr[j] == 0) {
				arr[j] = arr[j + 1];
				arr[j + 1] = 0;
			}
	cout << "преобразованный массив: \n";
	for (int i = 0; i < n; i++)
		cout << *(arr + i) << endl;

	return 0;
}

