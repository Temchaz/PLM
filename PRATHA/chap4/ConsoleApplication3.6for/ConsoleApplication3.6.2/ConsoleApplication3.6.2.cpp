// ConsoleApplication3.6.2.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct CandyBar
{
	string name;
	float weight;
	int quantity;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	CandyBar types[3];
	for (int i = 0; i < 3; i++) {
		cout << "¬ведите название " << i + 1 << " батончика: ";
		cin >> types[i].name;
		cout << "¬ведите вес " << i + 1 << " батончика: ";
		cin >> types[i].weight;
		cout << "¬ведите количество калорий в " << i + 1 << " батончике: ";
		cin >> types[i].quantity;
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 3; i++) {
		cout << i + 1 << "батончик: "
			<< types[i].name << endl
			<< types[i].weight << endl
			<< types[i].quantity << endl;
		cout << endl;
	}
	return 0;
}