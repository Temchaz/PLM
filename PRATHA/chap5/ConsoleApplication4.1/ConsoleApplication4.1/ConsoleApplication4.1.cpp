// ConsoleApplication4.1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	cout << "������� ������ ��������: ";
	int first_value;
	cin >> first_value;
	cout << "������� ������ ��������: ";
	int second_value;
	cin >> second_value;
	int sum = first_value + second_value;
	for (int i = 1; i<second_value - first_value; i++)
		sum += first_value + i;
	cout << "����� ���� ����� ����� �� "
		<< first_value
		<< " �� "
		<< second_value
		<< " ����� "
		<< sum << endl;
	return 0;
}

