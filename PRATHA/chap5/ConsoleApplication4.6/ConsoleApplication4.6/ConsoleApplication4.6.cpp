// ConsoleApplication4.6.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	cout << "������� ����������� ��������� � �������? ";
	int cnt;
	cin >> cnt;
	car * p_car = new car[cnt];
	for (int i = 0; i < cnt; i++) {
		cout << "���������� " << i + 1 << endl
			 << "������� �������������: \n";
		getline(cin, p_car[i].name);
		cout << "������� ��� �������:";
		cin >> p_car[i].year;
	}
	cout << "��� ���� ���������: \n";
	for (int i = 0; i < cnt; i++) {
		cout << p_car[i].year << " " << p_car[i].name << endl;
	}
	delete[] p_car;
	return 0;
}

