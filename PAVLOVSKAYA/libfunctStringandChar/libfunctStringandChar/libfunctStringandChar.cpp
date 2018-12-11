// libfunctStringandChar.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <conio.h>


int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	ifstream file;
	file.open("text.DAT");
	if (!file.is_open()) {
		cout << "�� ������� ������� ���� \"text.DAT\" " << endl;
		exit(EXIT_FAILURE);
	}
	char ch;
	// task 1
	while (file.read(&ch, 1)) cout << ch;	
	cout << endl << endl;
	file.clear();	// ������� eof
	file.seekg(0);	// ��������� �� ������ �����
	int cnt(0);
	int np=0;
	// task 2
	while (file.read(&ch, 1))				// ������ �� �������
		if (ch == '.' || ch == '!' || ch == '?') {
			np++;
			cout << "� ����������� �" << np << " ���������� ��������, �������� �� ���� � ��������: " << cnt << endl;
			cnt = 0;
		}
		else if (!isalnum(ch) && ch != ' ' && ch!= '\n')
			cnt++;
	cout << endl;
	file.clear();	
	file.seekg(0);
	string str;
	_getch();
	while (file.read(&ch, 1)) {
		cout << ch;
		if (ch == '.' || ch == '!' || ch == '?') {
			cout << endl;
			cout << str << endl << endl;
			str.clear();
			_getch();
		}
		else {
			if (!isalnum(ch) && ch != ' ' && ch != '\n')
				str += ch;
		}
	}
		
				
	return 0;
}

