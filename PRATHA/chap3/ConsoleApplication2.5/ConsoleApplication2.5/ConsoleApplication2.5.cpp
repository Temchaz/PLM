// ConsoleApplication2.5.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

double consumption(double d, double p) {
	return p / d;
}
int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	cout << "������� ���������� ���������� � ����������: ";
	int distance;
	cin >> distance;
	cout << "������� ���-�� ������ �������������� �������: ";
	int petrol;
	cin >> petrol;
	cout << "�� 1 �������� ��� ������������: " << consumption(distance, petrol) << " ������ �������" << endl;
	return 0;
}

