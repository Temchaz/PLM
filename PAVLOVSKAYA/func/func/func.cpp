// �������.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip> 

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	double a, b, c;
	cout << "������� �������� a: ";
	cin >> a;
	cout << "������� �������� b: ";
	cin >> b;
	cout << "������� �������� c: ";
	cin >> c;
	double x, x_last, dX;
	cout << "������� �������� X���: ";
	cin >> x;
	cout << "������� �������� X���: ";
	cin >> x_last;
	cout << "������� �������� dX: ";
	cin >> dX;
	double F;
	cout << setw(5) << "x" << setw(6) << "F(x)" << endl;
	for (x; x <= x_last; x += dX) {
		if (a < 0 && x != 0)
			F = a*x*x + b*b*x;
		else if (a > 0 && x == 0)
			F = x - a / (x - c);
		else
			F = 1 + x / c;
		if (~(int(a) | int(b)) & (int(b) | int(c)))
			cout << setw(5) << x << setw(5) << F << endl;
		else
			cout << setw(5) << x << setw(5) << int(F) << endl;
	}
	return 0;
}