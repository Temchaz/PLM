#pragma once
struct scan_info {		// ������ � ������� ���������
	char model[25];
	int price;
	double x_size;
	double y_size;
	int optr;
	int grey;
};

scan_info* inp_scan(int& cnt);	// ������� ����� ������ 
void write_file(scan_info *scan, int cnt);	// ������� ������ ������ � ���� 
