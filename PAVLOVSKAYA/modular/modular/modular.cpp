// modular.cpp: ���������� ����� ����� ��� ����������� ����������.
//


#include "stdafx.h"
#include <iostream>
#include <Windows.h>	//���������� ��� ������ getline()
#include <cctype>		//���������� ��� ������ isupper() � islower()
#include "lib.h"
#undef max;


int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int cnt = 0;
	scan_info* scan = inp_scan(cnt);
	write_file(scan, cnt);
	cout << endl;

	cout << "������� ����� �������: ";
	long num;
	scan_info si = { " ", 0, 0, 0, 0, 0 };
	cin >> num;
	FILE * fscan;
	fopen_s(&fscan, "scanners.bin", "rb");
	int num_scan;
	fread(&num_scan, sizeof(int), 1, fscan);
	if (num <= num_scan) {
		fseek(fscan, 4 + sizeof(scan_info)*(num - 1), ios::beg);
		fread(&si, sizeof(scan_info), 1, fscan);
		cout << "������������ ������: " << si.model << endl
			<< "����: " << si.price << endl
			<< "�������������� ������ ������� ������������: " << si.x_size << endl
			<< "������������ ������ ������� ������������: " << si.y_size << endl
			<< "���������� ����������: " << si.optr << endl
			<< "����� �������� ������: " << si.grey << endl;
	}
	else {
		cout << "������ ���, "
			<< "���� ���������: " << endl;
		for (int i = 0; i < num_scan; i++) {
			cout << i + 1 << " ������: " << endl;
			cout << "\t������������ ������: " << si.model << endl
				<< "\t����: " << si.price << endl
				<< "\t�������������� ������ ������� ������������: " << si.x_size << endl
				<< "\t������������ ������ ������� ������������: " << si.y_size << endl
				<< "\t���������� ����������: " << si.optr << endl
				<< "\t����� �������� ������: " << si.grey << endl;
		}
	}
	fclose(fscan);
	delete[cnt] scan;
	return 0;
}

