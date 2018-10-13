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
};

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	pizza * p_pizza = new pizza;
	cout << "Введите название пиццы: ";
	getline(cin, p_pizza->name);
	cout << "введите диаметр пиццы: ";
	cin >> p_pizza->diametr;
	cout << "введите вес пиццы: ";
	cin >> p_pizza->weight;
	cout << endl;
	cout << "название " << p_pizza->name << endl
		<< "ее диаметр " << p_pizza->diametr << endl
		<< "ее вес " << p_pizza->weight << endl;
	delete p_pizza;
	return 0;
}