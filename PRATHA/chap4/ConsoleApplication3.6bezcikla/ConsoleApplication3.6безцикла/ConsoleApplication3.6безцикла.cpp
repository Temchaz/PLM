// ConsoleApplication3.6.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	cout << "������� �������� 1 ���������: ";
	cin >> types[0].name;
	cout << "������� ��� 1 ���������: ";
	cin >> types[0].weight;
	cout << "������� ���������� ������� �  1 ���������: ";
	cin >> types[0].quantity;

	cout << endl;

	cout << "������� �������� 2 ���������: ";
	cin >> types[1].name;
	cout << "������� ��� 2 ���������: ";
	cin >> types[1].weight;
	cout << "������� ���������� ������� �  2 ���������: ";
	cin >> types[1].quantity;

	cout << endl;

	cout << "������� �������� 3 ���������: ";
	cin >> types[2].name;
	cout << "������� ��� 3 ���������: ";
	cin >> types[2].weight;
	cout << "������� ���������� ������� �  3 ���������: ";
	cin >> types[2].quantity;

	cout << endl;

	cout << "1 ��������: "
		<< types[0].name << endl
		<< types[0].weight << endl
		<< types[0].quantity << endl;
	cout << endl;

	cout << "2 ��������: "
		<< types[1].name << endl
		<< types[1].weight << endl
		<< types[1].quantity << endl;
	cout << endl;
	cout << "3 ��������: "
		<< types[2].name << endl
		<< types[2].weight << endl
		<< types[2].quantity << endl;
	return 0;
}

