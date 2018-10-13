// ConsoleApplication4.5.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");

	const char * months[12] = {
		"€нварь",   "февраль",
		"март",     "апрель",
		"май",      "июнь",
		"июль",	  "август",
		"сент€брь", "окт€брь",
		"но€брь",	  "декабрь",
	};

	int selling[12][3];
	int sum = 0,	
		y_sum = 0;

	for (int j = 0; j < 3; j++) {
		cout << "в " << j+1 << " году продали: \n";
		for (int i = 0; i < 12; i++) {
			cout << "\t введите кол-во продаж за " << months[i] <<": ";
			cin >> selling[i][j];
			y_sum += selling[i][j];
		};
		sum += y_sum;
		cout << "продажи за " << j + 1 << " год: " << y_sum << endl << endl;
		y_sum = 0;
	}
	cout << "общий объем продаж за 3 года составил: " << sum << endl;
	return 0;
}

