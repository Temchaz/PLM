// ConsoleApplication3.6.0.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
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
	CandyBar * types_bar = new CandyBar[3];
	types_bar[0] = { "�������", 55.0, 240 };
	types_bar[1] = { "������", 50.0, 260 };
	types_bar[2] = { "������", 38.0, 250 };
	cout << "1 ��������: \n"
		<< types_bar[0].name << endl
		<< types_bar[0].weight << endl
		<< types_bar[0].quantity << endl;

	cout << endl;

	cout << "2 ��������: \n"
		<< types_bar[1].name << endl
		<< types_bar[1].weight << endl
		<< types_bar[1].quantity << endl;

	cout << endl;

	cout << "3 ��������: \n"
		<< types_bar[2].name << endl
		<< types_bar[2].weight << endl
		<< types_bar[2].quantity << endl;
	return 0;
}

