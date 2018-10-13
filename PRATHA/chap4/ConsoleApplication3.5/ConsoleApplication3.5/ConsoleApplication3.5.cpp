// ConsoleApplication3.5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct CandyBar
{
	string name;
	float weight;
	int quantity;
}snack = {
	"Micha Munch",
	2.3,
	350
};

int main()
{
	cout << snack.name		<< endl
		 << snack.weight	<< endl
		 << snack.quantity	<< endl;
	return 0;
}

