// ConsoleApplication3.4getline.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	cout << "Enter your first name: ";
	string f_name;
	getline(cin,f_name);
	cout << "Enter your last name: ";
	string l_name;
	getline(cin, l_name);
	string total = l_name + ", " + f_name;
	cout << "Here's the information in a single string: " << total << endl;
	return 0;
}

