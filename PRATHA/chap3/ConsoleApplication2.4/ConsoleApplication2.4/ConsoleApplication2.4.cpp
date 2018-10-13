// ConsoleApplication2.4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	using namespace std;
	const int hr_in_day = 24,
		sec_in_min = 60,
		sec_in_hour = sec_in_min * 60,
		sec_in_day = sec_in_hour*hr_in_day;
	cout << "Enter the number  of seconds: ";
	long time;
	cin >> time;
	int days = int (time / sec_in_day);
	int hours = int ((time % sec_in_day) / sec_in_hour);
	int minutes = int((time % sec_in_hour) / sec_in_min);
	int seconds = int(time % sec_in_min);
	cout << time << " seconds = "
		 << days << " days, " 
		 << hours << " hours, " 
		 << minutes << " minutes, " 
		 << seconds << " seconds" << endl;
	return 0;
}

