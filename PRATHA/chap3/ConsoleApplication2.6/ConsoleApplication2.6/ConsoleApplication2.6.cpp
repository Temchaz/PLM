// ConsoleApplication2.6.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

double coup(double cons) {
	const double litr = 1 / 3.875;
	return 62.14 / (cons*litr);
}

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	cout << "������� ������ �������: ";
	double consumption;
	cin >> consumption;
	cout << coup(consumption) << endl;
	return 0;
}
