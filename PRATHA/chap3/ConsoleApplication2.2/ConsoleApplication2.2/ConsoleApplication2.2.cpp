// ConsoleApplication2.2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

double height(double f, double i) {
	return (f * 12 + i)*0.0254;
}

double weight(double w) {
	return w / 2.2;
}

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	cout << "������� ���-�� ����� � ����� �����: ";
	double ft;
	cin >> ft;
	cout << "������� ���-�� ������ � ����� �����: ";
	double inch;
	cin >> inch;
	cout << "������� ���-�� ������ � ����� ����:";
	double wft;
	cin >> wft;
	double bmi = weight(wft) / pow(height(ft, inch), 2);
	cout <<"������ ����� ����: "<< bmi << endl;
	return 0;
}

