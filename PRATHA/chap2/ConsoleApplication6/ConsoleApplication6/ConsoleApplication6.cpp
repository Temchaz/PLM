// ConsoleApplication6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void time(int h, int m) {
	cout <<"Time: " << h << ":" << m << endl;
}

int main()
{
	cout << "Enter the number of hours: ";
	int hr;
	cin >> hr;
	cout << "Enter the number of minutes: ";
	int mnt;
	cin >> mnt;
	time(hr, mnt);
	return 0;
}

