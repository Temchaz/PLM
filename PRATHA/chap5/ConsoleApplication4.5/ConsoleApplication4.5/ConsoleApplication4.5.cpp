// ConsoleApplication4.5.cpp: ���������� ����� ����� ��� ����������� ����������.
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

	int selling[12][3];
	int sum = 0,	
		y_sum = 0;

	for (int j = 0; j < 3; j++) {
		cout << "� " << j+1 << " ���� �������: \n";
		for (int i = 0; i < 12; i++) {
			cout << "\t ������� ���-�� ������ �� " << months[i] <<": ";
			cin >> selling[i][j];
			y_sum += selling[i][j];
		};
		sum += y_sum;
		cout << "������� �� " << j + 1 << " ���: " << y_sum << endl << endl;
		y_sum = 0;
	}
	cout << "����� ����� ������ �� 3 ���� ��������: " << sum << endl;
	return 0;
}

