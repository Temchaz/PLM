// functionsanddiles.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>	//библиотека для работы getline()
#include <cctype>		//библиотека для работы isupper() и islower()
#undef max;

using namespace std;
struct scan_info {		// данная в условие структура
	char model[25];
	int price;
	double x_size;
	double y_size;
	int optr;
	int grey;
};

scan_info* inp_scan(int& cnt) {					// функция ввода данных 
	cout << "введите количество сканеров: ";
	cin >> cnt;
	scan_info* scan = new scan_info [cnt];
	for (int i = 0; i < cnt; i++) {
		cout << i + 1 << " сканер: " << endl;
		cout << "\tВведите наименование модели: ";
		cin.ignore(std::numeric_limits<size_t>::max(), '\n');
		cin.getline(scan[i].model, 25);
		cout << "\tВведите цену: ";
		cin >> scan[i].price;
		cout << "\tВведите горизонтальный размер области сканирования: ";
		cin >> scan[i].x_size;
		cout << "\tВведите вертикальный размер области сканирования: ";
		cin >> scan[i].y_size;
		cout << "\tВведите оптическое разрешение: ";
		cin >> scan[i].optr;
		cout << "\tВведите число градаций серого: ";
		cin >> scan[i].grey;
	}
	return scan;
}

void write_file(scan_info *scan, int cnt) {					// функция записи данных в файл 
	FILE *fscan;					
	errno_t err = fopen_s(&fscan, "scanners.bin", "wb");	// проверка на правильность открытия файла 
	if (err) {
		cout << "The file was not opened" << endl;
		exit(1);
	}
	long cnt_scan = 0;
	fwrite(&cnt_scan, sizeof(long), 1, fscan);				// записываю значение счетчика по условия задачи
	for (int i = 0; i < cnt; i++)							// записываю данные о сканерах,
		if (scan[i].price>=200)								// имена которых начинаются с заглавной буквы и цена на которые больше 200
			if (isupper(scan[i].model[0])) {
				fwrite(&scan[i], sizeof(scan_info), 1, fscan);
				cnt_scan++;
			}
	for (int i = 0; i < cnt; i++)							// записываю данные о сканерах,
		if (scan[i].price >= 200)							// имена которых начинаются со строчной буквы и цена на которые больше 200
			if (islower(scan[i].model[0])) {
				fwrite(&scan[i], sizeof(scan_info), 1, fscan);
				cnt_scan++;
			}
	fseek(fscan, 0, ios::beg);								// устанавливаю позицию в начало 
	fwrite(&cnt_scan, sizeof(long), 1, fscan);				// записываю значение счетчика
	fclose(fscan);											// закрываю файл
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
		cout << "Наименование модели: "						   << si.model	<< endl
			 << "Цена: "									   << si.price	<< endl
			 << "Горизонтальный размер области сканирования: " << si.x_size << endl
			 << "Вертикальный размер области сканирования: "   << si.y_size << endl
			 << "Оптическое разрешение: "					   << si.optr	<< endl
			 << "Число градаций серого: "					   << si.grey	<< endl;
	}
	else {
		cout << "Такого нет, "
			 << "есть следующие: " << endl;
		for (int i = 0; i < num_scan; i++) {
			cout << i + 1 << " сканер: " << endl;
			cout << "\tНаименование модели: "						 << si.model	<< endl
				 << "\tЦена: "									     << si.price	<< endl
				 << "\tГоризонтальный размер области сканирования: " << si.x_size << endl
				 << "\tВертикальный размер области сканирования: "   << si.y_size << endl
				 << "\tОптическое разрешение: "					     << si.optr	<< endl
				 << "\tЧисло градаций серого: "					     << si.grey	<< endl;
		}
	}
	fclose(fscan);
	delete[cnt] scan; 
	return 0;
}

