// ConsoleApplication4.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

double fahr_temp(int f) {
	return 1.8*f + 32;
}

int main()
{
	using namespace std;
	cout << "Please enter a Celsius value : ";
	int cels;
	cin >> cels;
	cout << cels << " degrees Celsius is " << fahr_temp(cels) << " degrees Fahrenheit ." << endl;
	return 0;
}

