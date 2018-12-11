// ConsoleApplication6.6.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct maecenas {
		string name;
		double donations;
	};
	cout << "������� ���������� ���������: ";
	int cnt;
	cin >> cnt;
	maecenas * arr = new maecenas[cnt];
	for (int i(0); i < cnt; i++) {
		cout << "��� " << i + 1 << " ��������: ";
		cin >> arr[i].name;
		cout << arr[i].name << " �����������: $";
		cin >> arr[i].donations;
	}
	
	int grand_cnt = 0, patrons_cnt = 0;
	for (int i(0); i < cnt; i++)
		if (arr[i].donations > 10000) grand_cnt++;
		else patrons_cnt++;
	
	cout << endl << "G�and Pat�ons: " << endl;
	if (grand_cnt > 0) {
		for (int i = 0; i < cnt; i++)
			if (arr[i].donations > 10000)
				cout << arr[i].name << " ����������� $" << arr[i].donations << endl;
	}
	else cout << "none" << endl;

	cout << endl << "Pat�ons: " << endl;
	if (patrons_cnt > 0) {
		for (int i = 0; i < cnt; i++)
			if (arr[i].donations < 10000)
				cout << arr[i].name << " ����������� $" << arr[i].donations << endl;
	}
	else cout << "none" << endl;
	return 0;
}

