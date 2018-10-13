// ConsoleApplication2.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
const int ft = 12;

using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "введите свой рост в дюймах:____\b\b\b\b";
	int inch;
	cin >> inch;
	cout << "ваш рост составляет:" << inch / ft << " фута(ов) и " << inch % ft << " дюйма(ов)" << endl;
	return 0;
}