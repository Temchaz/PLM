// ConsoleApplication6.3.cpp: ���������� ����� ����� ��� ����������� ����������.
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
	cout << "���������� , ������� ���� �� ��������� �������� : " << endl
		 << "c) ������ p) �������"								 << endl
		 << "t) ������ g) ���� "								 << endl;
	char value;
	
	while (1) {
		cin >> value;
		switch (value) {
			case 'c': cout << "���� - ��� ������" << endl;
				break;
			case 'p': cout << "���������� - ��� �������" << endl;
				break;
			case 't': cout << "��� - ��� ������" << endl;
				break;
			case 'g': cout << "��������� - ��� ����" << endl;
				break;
			default: cout << "���������� , ������� �, �, t, ��� g:";
		};
	}
	return 0;
}

