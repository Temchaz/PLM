// ConsoleApplication4.4.cpp: определ€ет точку входа дл€ консольного приложени€.
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
	int selling[12];
	int sum = 0;
	for (int i = 0; i < 12; i++) {
		cout << "введите кол-во продаж за " << months[i] << ": ";
		cin >> selling[i];
		sum += selling[i];
	}
	cout << "общий объем продаж за год составил: " << sum << endl;
	return 0;
}

