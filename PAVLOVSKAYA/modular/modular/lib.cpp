#include "stdafx.h"
#include <iostream>
#include "lib.h"

scan_info* inp_scan(int& cnt) {					// функци€ ввода данных 
	using namespace std;
	cout << "введите количество сканеров: ";
	cin >> cnt;
	scan_info* scan = new scan_info[cnt];
	for (int i = 0; i < cnt; i++) {
		cout << i + 1 << " сканер: " << endl;
		cout << "\t¬ведите наименование модели: ";
		cin.ignore(std::numeric_limits<size_t>::max(), '\n');
		cin.getline(scan[i].model, 25);
		cout << "\t¬ведите цену: ";
		cin >> scan[i].price;
		cout << "\t¬ведите горизонтальный размер области сканировани€: ";
		cin >> scan[i].x_size;
		cout << "\t¬ведите вертикальный размер области сканировани€: ";
		cin >> scan[i].y_size;
		cout << "\t¬ведите оптическое разрешение: ";
		cin >> scan[i].optr;
		cout << "\t¬ведите число градаций серого: ";
		cin >> scan[i].grey;
	}
	return scan;
}

void write_file(scan_info *scan, int cnt) {					// функци€ записи данных в файл 
	FILE *fscan;
	errno_t err = fopen_s(&fscan, "scanners.bin", "wb");	// проверка на правильность открыти€ файла 
	if (err) {
		std::cout << "The file was not opened" << std::endl;
		exit(1);
	}
	long cnt_scan = 0;
	fwrite(&cnt_scan, sizeof(long), 1, fscan);				// записываю значение счетчика по услови€ задачи
	for (int i = 0; i < cnt; i++)							// записываю данные о сканерах,
		if (scan[i].price >= 200)								// имена которых начинаютс€ с заглавной буквы и цена на которые больше 200
			if (isupper(scan[i].model[0])) {
				fwrite(&scan[i], sizeof(scan_info), 1, fscan);
				cnt_scan++;
			}
	for (int i = 0; i < cnt; i++)							// записываю данные о сканерах,
		if (scan[i].price >= 200)							// имена которых начинаютс€ со строчной буквы и цена на которые больше 200
			if (islower(scan[i].model[0])) {
				fwrite(&scan[i], sizeof(scan_info), 1, fscan);
				cnt_scan++;
			}
	fseek(fscan, 0, std::ios::beg);								// устанавливаю позицию в начало 
	fwrite(&cnt_scan, sizeof(long), 1, fscan);				// записываю значение счетчика
	fclose(fscan);											// закрываю файл
}