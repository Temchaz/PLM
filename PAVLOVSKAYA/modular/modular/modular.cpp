// modular.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>
#include <Windows.h>	//библиотека для работы getline()
#include <cctype>		//библиотека для работы isupper() и islower()
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

	cout << "введите номер сканера: ";
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
		cout << "Наименование модели: " << si.model << endl
			<< "Цена: " << si.price << endl
			<< "Горизонтальный размер области сканирования: " << si.x_size << endl
			<< "Вертикальный размер области сканирования: " << si.y_size << endl
			<< "Оптическое разрешение: " << si.optr << endl
			<< "Число градаций серого: " << si.grey << endl;
	}
	else {
		cout << "Такого нет, "
			<< "есть следующие: " << endl;
		for (int i = 0; i < num_scan; i++) {
			cout << i + 1 << " сканер: " << endl;
			cout << "\tНаименование модели: " << si.model << endl
				<< "\tЦена: " << si.price << endl
				<< "\tГоризонтальный размер области сканирования: " << si.x_size << endl
				<< "\tВертикальный размер области сканирования: " << si.y_size << endl
				<< "\tОптическое разрешение: " << si.optr << endl
				<< "\tЧисло градаций серого: " << si.grey << endl;
		}
	}
	fclose(fscan);
	delete[cnt] scan;
	return 0;
}

