// ConsoleApplication6.6.cpp: определяет точку входа для консольного приложения.
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
	cout << "Введите количество меценатов: ";
	int cnt;
	cin >> cnt;
	maecenas * arr = new maecenas[cnt];
	for (int i(0); i < cnt; i++) {
		cout << "Имя " << i + 1 << " мецената: ";
		cin >> arr[i].name;
		cout << arr[i].name << " пожертвовал: $";
		cin >> arr[i].donations;
	}
	
	int grand_cnt = 0, patrons_cnt = 0;
	for (int i(0); i < cnt; i++)
		if (arr[i].donations > 10000) grand_cnt++;
		else patrons_cnt++;
	
	cout << endl << "Gгand Patгons: " << endl;
	if (grand_cnt > 0) {
		for (int i = 0; i < cnt; i++)
			if (arr[i].donations > 10000)
				cout << arr[i].name << " пожертвовал $" << arr[i].donations << endl;
	}
	else cout << "none" << endl;

	cout << endl << "Patгons: " << endl;
	if (patrons_cnt > 0) {
		for (int i = 0; i < cnt; i++)
			if (arr[i].donations < 10000)
				cout << arr[i].name << " пожертвовал $" << arr[i].donations << endl;
	}
	else cout << "none" << endl;
	return 0;
}

