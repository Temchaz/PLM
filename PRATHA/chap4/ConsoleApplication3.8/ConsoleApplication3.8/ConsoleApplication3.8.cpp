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
};

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	pizza * p_pizza = new pizza;
	cout << "������� �������� �����: ";
	getline(cin, p_pizza->name);
	cout << "������� ������� �����: ";
	cin >> p_pizza->diametr;
	cout << "������� ��� �����: ";
	cin >> p_pizza->weight;
	cout << endl;
	cout << "�������� " << p_pizza->name << endl
		<< "�� ������� " << p_pizza->diametr << endl
		<< "�� ��� " << p_pizza->weight << endl;
	delete p_pizza;
	return 0;
}