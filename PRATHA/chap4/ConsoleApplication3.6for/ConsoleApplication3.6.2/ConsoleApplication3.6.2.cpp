// ConsoleApplication3.6.2.cpp: ���������� ����� ����� ��� ����������� ����������.
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
		cout << "������� �������� " << i + 1 << " ���������: ";
		cin >> types[i].name;
		cout << "������� ��� " << i + 1 << " ���������: ";
		cin >> types[i].weight;
		cout << "������� ���������� ������� � " << i + 1 << " ���������: ";
		cin >> types[i].quantity;
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 3; i++) {
		cout << i + 1 << "��������: "
			<< types[i].name << endl
			<< types[i].weight << endl
			<< types[i].quantity << endl;
		cout << endl;
	}
	return 0;
}