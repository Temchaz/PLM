// ConsoleApplication4.7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>

int main()
{
	using namespace std;
	char word[15];
	int cnt = 0;
	do {
		cin >> word;
		++cnt;
	} while (strcmp(word, "done"));
	cout << cnt-1 << endl;
	return 0;
}

