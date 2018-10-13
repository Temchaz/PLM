// ConsoleApplication4.6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct car
{
	string name;
	int year;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Сколько автомобилей поместить в каталог? ";
	int cnt;
	cin >> cnt;
	car * p_car = new car[cnt];
	for (int i = 0; i < cnt; i++) {
		cout << "Автомобиль " << i + 1 << endl
			 << "Введите производителя: \n";
		getline(cin, p_car[i].name);
		cout << "Укажите год выпуска:";
		cin >> p_car[i].year;
	}
	cout << "Вот ваша коллекция: \n";
	for (int i = 0; i < cnt; i++) {
		cout << p_car[i].year << " " << p_car[i].name << endl;
	}
	delete[] p_car;
	return 0;
}

