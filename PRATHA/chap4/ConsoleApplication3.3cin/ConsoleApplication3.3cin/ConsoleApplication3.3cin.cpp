// ConsoleApplication3.3cin.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>

int main()
{
	using namespace std;
	const int SIZE = 10;
	cout << "Enter your first name: ";
	char f_name[SIZE];
	cin >> f_name;
	cout << "Enter your last name: ";
	char l_name[SIZE];
	cin >> l_name;
	char total[sizeof(f_name) + sizeof(l_name) + 2];
	char comma[] = ", ";
	strcat(l_name, comma); // ����� �� ������� ������ c4996 
						   // ��������� � ����������� �������������   _CRT_SECURE_NO_WARNINGS 
	strcat(l_name, f_name);
	cout << "Here's the information in a single string: "
		<< l_name << endl;
	return 0;
}

