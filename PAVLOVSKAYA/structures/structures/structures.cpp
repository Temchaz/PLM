// structures.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <Windows.h>
#undef max

struct MARSH {
	char punct[20];
	int num;
	int hr, minute;
};
int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	MARSH arr[8];
	for (int i = 0; i < 8; i++) {
		cout <<"������� ����� � ��������: " << endl;
		cout << "\t������� ����� ����������: ";
		cin.getline(arr[i].punct, 20);
		cout << "\t������� ����� ������: ";
		cin >> arr[i].num;
		cout << "\t������� ���� �����������: ";
		cin >> arr[i].hr;
		cout << "\t������� ������ �����������: ";
		cin >> arr[i].minute;
		cin.ignore(std::numeric_limits<size_t>::max(), '\n');
	}

	MARSH t;
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			if (arr[j].num > arr[j + 1].num) {
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}

	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout <<"\t����� ������: "<< arr[i].num;
		cout << "\t����� ����������: " << arr[i].punct << endl;
		cout << "\t����� �����������: " << arr[i].hr << ":" << arr[i].hr << endl;
		cout << endl;
	}
	
	cout << "������� ����� ������: ";
	int k;
	cin >> k;
	int not_found = 1;
	for (int i = 0; i < 8; i++)
		if (arr[i].num == k) {
			not_found = 0;
			cout << "����� ����������: " << arr[i].punct << endl;
			cout << "����� �����������: " << arr[i].hr << ":" << arr[i].hr << endl;
			break;
		}
	if (not_found)
		cout << "��� ����� �������" << endl;
	return 0;
}

