// ConsoleApplication2.1.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
const int ft = 12;

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ���� ���� � ������:____\b\b\b\b";
	int inch;
	cin >> inch;
	cout << "��� ���� ����������:" << inch / ft << " ����(��) � " << inch % ft << " �����(��)" << endl;
	return 0;
}