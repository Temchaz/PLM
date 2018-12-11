// ConsoleApplication6.4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int strsize = 15;
	struct bop {
		char fullname[strsize];
		char title[strsize];
		char bopname[strsize];
		int preference;
	};
	bop arr[3] = {
		{"Ivan Ivanov", "Boss", "Stroustrup", 2},
		{"Petr Petrov", "Programmer", "Plankton", 1},
		{"Olesha Belov", "Trainee", "Lamer", 0},
	};
	
	cout << endl;
	cout << "a. ���������� �� ������		b. ���������� �� ���������� "	 << endl
		 << "�. ���������� �� ������ ���	d. ���������� �� ������������� " << endl
		 << "q. �����"														 << endl;
	cout << endl;
	char ch('a');
	do {
		cout << "��� �����: ";
		cin >> ch;
		switch (ch) {
			case 'a': for (int i = 0; i < 3; i++)
				  cout << arr[i].fullname << endl;
				  break;
			case 'b': for (int i = 0; i < 3; i++)
				cout << arr[i].title << endl;
				break;
			case 'c': for (int i = 0; i < 3; i++)
				cout << arr[i].bopname << endl;
				break;
			case 'd': for (int i = 0; i < 3; i++)
				switch (arr[i].preference) {
				case 0: cout << arr[i].fullname << endl;
					break;
				case 1: cout << arr[i].title << endl;
					break;
				case 2: cout << arr[i].bopname << endl;
					break;
				default: break;
				}
				break;
			default: if (ch!='q') cout << "��� ������ ������" << endl;
		}
	} while (ch != 'q');
	cout << "����!" << endl;

	return 0;
}

