// ConsoleApplication3.2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
	using namespace std;
	setlocale(LC_ALL,"Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name, dessert;
	cout << "������� ���� ��� : \n";
	getline(cin, name); // ������ �� ������� ����� ������
	cout << "������� ��� ������� ������ : \n";
	getline(cin, dessert);
	cout << "� ���� ���� ������� " << dessert;
	cout << " ��� ��� , " << name << ".\n";
	return 0;
}

