// ConsoleApplication�������.cpp: ���������� ����� ����� ��� ����������� ����������.
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

void print_bar(CandyBar* bar) {
	cout << "1 ��������: \n"
		<< bar->name << endl
		<< bar->weight << endl
		<< bar->quantity << endl;

	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	CandyBar * types_bar = new CandyBar[3]; 
	types_bar[0] = { "�������", 55.0, 240 };
	types_bar[1] = { "������", 50.0, 260 };
	types_bar[2] = { "������", 38.0, 250 };
	print_bar(&types_bar[0]);
	print_bar(&types_bar[1]);
	print_bar(&types_bar[2]);
	return 0;
}