// ConsoleApplication4.3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	double Daphne = 100,
		   Cleo = 100;
	int cnt=0;
	do {
		Daphne += 0.1 * 100;
		Cleo += 0.05 * Cleo;
		cnt++;
		cout << "Баланс Клео: $"   << Cleo   << endl
			 << "Баланс Дафины: $" << Daphne << endl
			 << endl;
	} while (Daphne >= Cleo);
	cout << "Для того, чтобы баланс Клео превысил баланс Дафины, понадобится " 
		 << cnt << " лет." << endl;
	return 0;
}

