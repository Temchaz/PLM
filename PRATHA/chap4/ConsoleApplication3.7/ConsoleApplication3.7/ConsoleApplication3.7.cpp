// ConsoleApplication3.7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct pizza
{
	string name;
	int diametr;
	double weight;
}inf_pizza;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "������� �������� �����: ";
	getline(cin, inf_pizza.name);
	cout << "������� ������� �����: ";
	cin >> inf_pizza.diametr;
	cout << "������� ��� �����: ";
	cin >> inf_pizza.weight;
	cout << endl;
	cout << "�������� "   << inf_pizza.name	   << endl
		 << "�� ������� " << inf_pizza.diametr << endl
		 << "�� ��� "	  << inf_pizza.weight  << endl;
	return 0;
}

