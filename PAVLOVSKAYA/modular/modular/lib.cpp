#include "stdafx.h"
#include <iostream>
#include "lib.h"

scan_info* inp_scan(int& cnt) {					// ������� ����� ������ 
	using namespace std;
	cout << "������� ���������� ��������: ";
	cin >> cnt;
	scan_info* scan = new scan_info[cnt];
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
		std::cout << "The file was not opened" << std::endl;
		exit(1);
	}
	long cnt_scan = 0;
	fwrite(&cnt_scan, sizeof(long), 1, fscan);				// ��������� �������� �������� �� ������� ������
	for (int i = 0; i < cnt; i++)							// ��������� ������ � ��������,
		if (scan[i].price >= 200)								// ����� ������� ���������� � ��������� ����� � ���� �� ������� ������ 200
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
	fseek(fscan, 0, std::ios::beg);								// ������������ ������� � ������ 
	fwrite(&cnt_scan, sizeof(long), 1, fscan);				// ��������� �������� ��������
	fclose(fscan);											// �������� ����
}