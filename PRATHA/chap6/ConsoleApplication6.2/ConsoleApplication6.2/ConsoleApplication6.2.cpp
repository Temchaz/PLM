// ConsoleApplication6.2.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
const int size_arr = 10;

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double arr[size_arr];
	int i = 0;
	double arr_sum = 0;
	int cnt = 0;
	while (i < size_arr && cin >> arr[i]) {
		arr_sum = arr_sum + arr[i];
		cnt++;
		i++;
	}
	double mean = arr_sum / cnt;
	int cnt_arr = 0;
	for (int j = 0; j < cnt; j++)
		if (arr[j] > mean) {
			cnt_arr++;
		}
	cout << "—реднее значение полученных чисел: " << mean << endl
		 << " оличество значение, превышающих среднее: " << cnt_arr << endl;
	return 0;
}

