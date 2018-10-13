// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
void func1() {
	cout << "Three blind mice" << endl;
}

void func2() {
	cout << "See how they run " << endl;
}

int main()
{
	func1();
	func1();
	func2();
	func2();
    return 0;
}

