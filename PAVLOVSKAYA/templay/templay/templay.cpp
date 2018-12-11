// array.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

template <typename T>
T maxAbs(T arr[], int n) {
	T max_abs(0);
	for (int i(0); i < n; i++) {
		if (abs(arr[i]) > abs(max_abs))
			max_abs = arr[i];
	}
	return max_abs;
}

template <typename T>
T sumBetween(T arr[], int n) {
	T sum(0);
	bool state(0);
	for (int i(0); i < n; i++) {
		if (arr[i] > 0 && state == 0)
			state = 1;
		else if (state == 1 && arr[i] <= 0)
			sum += arr[i];
		else if (state == 1 && arr[i] > 0)
			break;
	}
	return sum;
}

template <typename T>
void permutations(T arr[], int n) {
	int t;
	for (int i(0); i < n - 1; i++)
		for (int j(0); j < n - 1; j++)
			if (arr[j] == 0) {
				arr[j] = arr[j + 1];
				arr[j + 1] = 0;
			}

}
int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	const int N(10);

	// проверяем функции для типа double
	cout << "DOUBLE: " << endl;
	double arrDBL[] = { 1.23, 0.0, 34.2, -21.0, 0.0, 100.223, 77.675, 0.0, 8.0, -254.82 };
	//maxAbs
	if (maxAbs(arrDBL, N) == -254.82) cout << "функция maxAbs для типа double работает правильно";
	else cout << "функция maxAbs для типа double работает НЕ правильно!!!";
	cout << endl;
	cout << "максимальный по модулю элемент масиива: "
		<< maxAbs(arrDBL, N) << endl << endl;
	//sumBetween
	if (sumBetween(arrDBL, N) == 0) cout << "функция sumBetween для типа double работает правильно";
	else cout << "функция sumBetween для типа double работает НЕ правильно!!!";
	cout << endl;
	cout << "сумма элементов массива между первым и вторым " << endl
		<< "положительными элементами: " << sumBetween(arrDBL, N) << endl << endl;
	//permutations
	cout << "исходный массив: " << endl;
	for (int i(0); i < N; i++) cout << arrDBL[i] << " ";
	permutations(arrDBL, N);
	cout << endl << "преборазованный массив: " << endl;
	for (int i(0); i < N; i++)
		cout << *(arrDBL + i) << " ";
	cout << endl << endl;



	// проверяем функции для типа int
	cout << "INT: " << endl;
	int arrINT[] = { 1, 0, -34, 21, 0, 100, 77, 0, 8, -254 };
	//maxAbs
	if (maxAbs(arrINT, N) == -254) cout << "функция maxAbs для типа int работает правильно";
	else cout << "функция maxAbs для типа int работает НЕ правильно!!!";
	cout << endl;
	cout << "максимальный по модулю элемент масиива: "
		<< maxAbs(arrINT, N) << endl << endl;
	//sumBetween
	if (sumBetween(arrINT, N) == -34) cout << "функция sumBetween для типа int работает правильно";
	else cout << "функция sumBetween для типа int работает НЕ правильно!!!";
	cout << endl;
	cout << "сумма элементов массива между первым и вторым " << endl
		<< "положительными элементами: " << sumBetween(arrINT, N) << endl << endl;
	//permutations
	cout << "исходный массив: " << endl;
	for (int i(0); i < N; i++) cout << arrINT[i] << " ";
	permutations(arrINT, N);
	cout << endl << "преборазованный массив: " << endl;
	for (int i(0); i < N; i++)
		cout << *(arrINT + i) << " ";
	cout << endl << endl;



	// проверяем функции для типа float 
	cout << "FLOAT: " << endl;
	float arrFLT[] = { 23.23, -43.25, 0.0, -23.43, -10.23, 0.0 , 30.2, 24.2, 0.0, 10.2 };
	// maxAbs
	if (maxAbs(arrFLT, N) == -43.25) cout << "функция maxAbs для типа float работает правильно";
	else cout << "функция maxAbs для типа float работает НЕ правильно!!!";
	cout << endl;
	cout << "максимальный по модулю элемент масиива: "
		<< maxAbs(arrFLT, N) << endl << endl;
	//sumBetween
	if (sumBetween(arrFLT, N) == -76.91F) cout << "функция sumBetween для типа float работает правильно";
	else cout << "функция sumBetween для типа float работает НЕ правильно!!!";
	cout << endl;
	cout << "сумма элементов массива между первым и вторым " << endl
		<< "положительными элементами: " << sumBetween(arrFLT, N) << endl << endl;
	//permutations
	cout << "исходный массив: " << endl;
	for (int i(0); i < N; i++) cout << arrFLT[i] << " ";
	permutations(arrFLT, N);
	cout << endl << "преборазованный массив: " << endl;
	for (int i(0); i < N; i++)
		cout << *(arrFLT + i) << " ";
	cout << endl << endl;


	return 0;
}

