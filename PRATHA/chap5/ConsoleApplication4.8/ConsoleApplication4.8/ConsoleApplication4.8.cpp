// ConsoleApplication4.8.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string word;
	int cnt = 0;
	do {
		cin >> word;
		++cnt;
	} while (word !="done");
	cout << cnt - 1 << endl;
	return 0;
}

