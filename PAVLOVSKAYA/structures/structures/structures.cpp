// structures.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <Windows.h>
#undef max

struct MARSH {
	char punct[20];
	int num;
	int hr, minute;
};
int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	MARSH arr[8];
	for (int i = 0; i < 8; i++) {
		cout <<"введите даные о маршруте: " << endl;
		cout << "\tвведите пункт назначения: ";
		cin.getline(arr[i].punct, 20);
		cout << "\tвведите номер поезда: ";
		cin >> arr[i].num;
		cout << "\tвведите часы отправления: ";
		cin >> arr[i].hr;
		cout << "\tвведите минуты отправления: ";
		cin >> arr[i].minute;
		cin.ignore(std::numeric_limits<size_t>::max(), '\n');
	}

	MARSH t;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			if (arr[j].num > arr[j + 1].num) {
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}

	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout <<"\tномер поезда: "<< arr[i].num;
		cout << "\tпункт назначения: " << arr[i].punct << endl;
		cout << "\tвремя отправления: " << arr[i].hr << ":" << arr[i].hr << endl;
		cout << endl;
	}
	
	cout << "введите номер поезда: ";
	int k;
	cin >> k;
	int not_found = 1;
	for (int i = 0; i < 8; i++)
		if (arr[i].num == k) {
			not_found = 0;
			cout << "пункт назначения: " << arr[i].punct << endl;
			cout << "время отправления: " << arr[i].hr << ":" << arr[i].hr << endl;
			break;
		}
	if (not_found)
		cout << "нет таких поездов" << endl;
	return 0;
}

