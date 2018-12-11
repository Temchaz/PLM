#pragma once
struct scan_info {		// данная в условие структура
	char model[25];
	int price;
	double x_size;
	double y_size;
	int optr;
	int grey;
};

scan_info* inp_scan(int& cnt);	// функция ввода данных 
void write_file(scan_info *scan, int cnt);	// функция записи данных в файл 
