// ConsoleApplication4.4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	const char * months[12] = {
		"������",   "�������",
		"����",     "������",
		"���",      "����",
		"����",	  "������",
		"��������", "�������",
		"������",	  "�������",
	};
	int selling[12];
	int sum = 0;
	for (int i = 0; i < 12; i++) {
		cout << "������� ���-�� ������ �� " << months[i] << ": ";
		cin >> selling[i];
		sum += selling[i];
	}
	cout << "����� ����� ������ �� ��� ��������: " << sum << endl;
	return 0;
}

