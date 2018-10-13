// ConsoleApplication3.6.cpp: определ€ет точку входа дл€ консольного приложени€.
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

	cout << "¬ведите название 1 батончика: ";
	cin >> types[0].name;
	cout << "¬ведите вес 1 батончика: ";
	cin >> types[0].weight;
	cout << "¬ведите количество калорий в  1 батончике: ";
	cin >> types[0].quantity;

	cout << endl;

	cout << "¬ведите название 2 батончика: ";
	cin >> types[1].name;
	cout << "¬ведите вес 2 батончика: ";
	cin >> types[1].weight;
	cout << "¬ведите количество калорий в  2 батончике: ";
	cin >> types[1].quantity;

	cout << endl;

	cout << "¬ведите название 3 батончика: ";
	cin >> types[2].name;
	cout << "¬ведите вес 3 батончика: ";
	cin >> types[2].weight;
	cout << "¬ведите количество калорий в  3 батончике: ";
	cin >> types[2].quantity;

	cout << endl;

	cout << "1 батончик: "
		<< types[0].name << endl
		<< types[0].weight << endl
		<< types[0].quantity << endl;
	cout << endl;

	cout << "2 батончик: "
		<< types[1].name << endl
		<< types[1].weight << endl
		<< types[1].quantity << endl;
	cout << endl;
	cout << "3 батончик: "
		<< types[2].name << endl
		<< types[2].weight << endl
		<< types[2].quantity << endl;
	return 0;
}

