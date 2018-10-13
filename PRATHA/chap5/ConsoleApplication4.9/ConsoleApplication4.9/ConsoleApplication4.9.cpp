// ConsoleApplication4.9.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <Windows.h>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "¬ведите количество строк: ";
	int cnt;
	cin >> cnt;
	char * stars = new char[cnt+1];
	stars[cnt] = '\0';
	for (int i = 1; i<=cnt ; i++) {
		for (int j = 0; j<=cnt-i; j++) {
			stars[j] = '.';
		}
		
		for (int j = cnt-1; j>=cnt-i; j--) {
			stars[j] = '*';
		}

		
		cout << stars << endl;
	}
	delete [] stars;
	return 0;
}