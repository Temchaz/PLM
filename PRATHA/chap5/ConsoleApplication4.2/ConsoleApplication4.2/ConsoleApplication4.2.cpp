// ConsoleApplication4.2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	int number;
	int sum = 0;
	do {
		cout << "������� �����: ";
		cin >> number;
		sum += number;
	} while (number);
	cout << "����������� ����� �����: " << sum << endl;
	return 0;
}

