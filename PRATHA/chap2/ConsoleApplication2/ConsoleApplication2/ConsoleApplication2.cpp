// ConsoleApplication2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int farlong(int f) {
	return f * 220;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ���������� � ���������: ";
	int far;
	cin >> far;
	cout << "� ����� ���: " << farlong(far) << endl;
	return 0;
}

