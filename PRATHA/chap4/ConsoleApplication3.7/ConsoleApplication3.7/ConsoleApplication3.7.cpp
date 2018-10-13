// ConsoleApplication3.7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

struct pizza
{
	string name;
	int diametr;
	double weight;
}inf_pizza;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите название пиццы: ";
	getline(cin, inf_pizza.name);
	cout << "введите диаметр пиццы: ";
	cin >> inf_pizza.diametr;
	cout << "введите вес пиццы: ";
	cin >> inf_pizza.weight;
	cout << endl;
	cout << "название "   << inf_pizza.name	   << endl
		 << "ее диаметр " << inf_pizza.diametr << endl
		 << "ее вес "	  << inf_pizza.weight  << endl;
	return 0;
}

