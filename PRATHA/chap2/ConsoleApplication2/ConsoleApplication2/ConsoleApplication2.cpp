// ConsoleApplication2.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int farlong(int f) {
	return f * 220;
}
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "введите рассто€ние в фарлонгах: ";
	int far;
	cin >> far;
	cout << "в €рдах это: " << farlong(far) << endl;
	return 0;
}

