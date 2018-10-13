// ConsoleApplication3.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>

int main()
{
	using namespace std;
	setlocale(LC_ALL,"Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name, dessert;
	cout << "Введите ваше имя : \n";
	getline(cin, name); // читать до символа новой строки
	cout << "Введите ваш любимый десерт : \n";
	getline(cin, dessert);
	cout << "У меня есть вкусный " << dessert;
	cout << " для вас , " << name << ".\n";
	return 0;
}

