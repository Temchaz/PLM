// functionsanddiles.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>	//���������� ��� ������ getline()
#include <cctype>		//���������� ��� ������ isupper() � islower()
#undef max;

using namespace std;
struct scan_info {		// ������ � ������� ���������
	char model[25];
	int price;
	double x_size;
	double y_size;
	int optr;
	int grey;
};

scan_info* inp_scan(int& cnt) {					// ������� ����� ������ 
	cout << "������� ���������� ��������: ";
	cin >> cnt;
	scan_info* scan = new scan_info [cnt];
	for (int i = 0; i < cnt; i++) {
		cout << i + 1 << " ������: " << endl;
		cout << "\t������� ������������ ������: ";
		cin.ignore(std::numeric_limits<size_t>::max(), '\n');
		cin.getline(scan[i].model, 25);
		cout << "\t������� ����: ";
		cin >> scan[i].price;
		cout << "\t������� �������������� ������ ������� ������������: ";
		cin >> scan[i].x_size;
		cout << "\t������� ������������ ������ ������� ������������: ";
		cin >> scan[i].y_size;
		cout << "\t������� ���������� ����������: ";
		cin >> scan[i].optr;
		cout << "\t������� ����� �������� ������: ";
		cin >> scan[i].grey;
	}
	return scan;
}

void write_file(scan_info *scan, int cnt) {					// ������� ������ ������ � ���� 
	FILE *fscan;					
	errno_t err = fopen_s(&fscan, "scanners.bin", "wb");	// �������� �� ������������ �������� ����� 
	if (err) {
		cout << "The file was not opened" << endl;
		exit(1);
	}
	long cnt_scan = 0;
	fwrite(&cnt_scan, sizeof(long), 1, fscan);				// ��������� �������� �������� �� ������� ������
	for (int i = 0; i < cnt; i++)							// ��������� ������ � ��������,
		if (scan[i].price>=200)								// ����� ������� ���������� � ��������� ����� � ���� �� ������� ������ 200
			if (isupper(scan[i].model[0])) {
				fwrite(&scan[i], sizeof(scan_info), 1, fscan);
				cnt_scan++;
			}
	for (int i = 0; i < cnt; i++)							// ��������� ������ � ��������,
		if (scan[i].price >= 200)							// ����� ������� ���������� �� �������� ����� � ���� �� ������� ������ 200
			if (islower(scan[i].model[0])) {
				fwrite(&scan[i], sizeof(scan_info), 1, fscan);
				cnt_scan++;
			}
	fseek(fscan, 0, ios::beg);								// ������������ ������� � ������ 
	fwrite(&cnt_scan, sizeof(long), 1, fscan);				// ��������� �������� ��������
	fclose(fscan);											// �������� ����
}

int main()
{
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
		cout << "������������ ������: "						   << si.model	<< endl
			 << "����: "									   << si.price	<< endl
			 << "�������������� ������ ������� ������������: " << si.x_size << endl
			 << "������������ ������ ������� ������������: "   << si.y_size << endl
			 << "���������� ����������: "					   << si.optr	<< endl
			 << "����� �������� ������: "					   << si.grey	<< endl;
	}
	else {
		cout << "������ ���, "
			 << "���� ���������: " << endl;
		for (int i = 0; i < num_scan; i++) {
			cout << i + 1 << " ������: " << endl;
			cout << "\t������������ ������: "						 << si.model	<< endl
				 << "\t����: "									     << si.price	<< endl
				 << "\t�������������� ������ ������� ������������: " << si.x_size << endl
				 << "\t������������ ������ ������� ������������: "   << si.y_size << endl
				 << "\t���������� ����������: "					     << si.optr	<< endl
				 << "\t����� �������� ������: "					     << si.grey	<< endl;
		}
	}
	fclose(fscan);
	delete[cnt] scan; 
	return 0;
}

