// ConsoleApplication6.3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Пожалуйста , введите одно из следующих значений : " << endl
		 << "c) хищник p) пианист"								 << endl
		 << "t) дерево g) игра "								 << endl;
	char value;
	
	while (1) {
		cin >> value;
		switch (value) {
			case 'c': cout << "Волк - это хищник" << endl;
				break;
			case 'p': cout << "Рахманинов - это пианист" << endl;
				break;
			case 't': cout << "Дуб - это дерево" << endl;
				break;
			case 'g': cout << "Догонялки - это игра" << endl;
				break;
			default: cout << "Пожалуйста , введите с, р, t, или g:";
		};
	}
	return 0;
}

