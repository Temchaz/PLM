// ConsoleApplication4.3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	double Daphne = 100,
		   Cleo = 100;
	int cnt=0;
	do {
		Daphne += 0.1 * 100;
		Cleo += 0.05 * Cleo;
		cnt++;
		cout << "������ ����: $"   << Cleo   << endl
			 << "������ ������: $" << Daphne << endl
			 << endl;
	} while (Daphne >= Cleo);
	cout << "��� ����, ����� ������ ���� �������� ������ ������, ����������� " 
		 << cnt << " ���." << endl;
	return 0;
}

