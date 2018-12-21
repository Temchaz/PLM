// matrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	double matrix[10][10] = {
		{1,2,3,4,5,6,7,8,9,10},
		{-11.1,12,13,14,15,16,17,18,19,20},
		{21.2,-22.3,23,24,25,26,27,28,29,30},
		{-31.4,32.5,-33.6,34,35,36,-37,38,39,40},
		{41.7,-42.8,43.9,-44.1,45,46,47,48,49,50},
		{-51.2,52.3,-53.4,54.5,-55.6,56,57,58,59,60},
		{61.7,-62.8,63.9,-64.1,65.2,-66.3,67,68,69,70},
		{-71.4,72.4,-73.6,74.7,-75.8,76.9,-77.1,78,79,80},
		{81.2,-82.3,83.4,-84.5,85.6,-86.7,87.8,-88.9,89,90},
		{-91.1,92.2,-93.3,94.4,-95.5,96.6,-97.7,98.8,-99.9,100},
	};
	double smooth_matrix[10][10];
	smooth_matrix[0][0] = (matrix[0][1] + matrix[1][0] + matrix[1][1]) / 3;
	smooth_matrix[0][9] = (matrix[0][8] + matrix[1][9] + matrix[1][8]) / 3;
	smooth_matrix[9][0] = (matrix[8][0] + matrix[9][1] + matrix[8][1]) / 3;
	smooth_matrix[9][9] = (matrix[9][8] + matrix[8][9] + matrix[8][8]) / 3;
	for (int i = 1; i < 9; i++) {
		smooth_matrix[0][i] = (matrix[0][i - 1] + matrix[0][i + 1] + matrix[1][i] + matrix[1][i - 1] + matrix[1][i + 1]) / 5;
		smooth_matrix[9][i] = (matrix[9][i - 1] + matrix[9][i + 1] + matrix[8][i] + matrix[8][i - 1] + matrix[8][i + 1]) / 5;
		smooth_matrix[i][0] = (matrix[i - 1][0] + matrix[i + 1][0] + matrix[i][1] + matrix[i - 1][1] + matrix[i + 1][1]) / 5;
		smooth_matrix[i][9] = (matrix[i - 1][9] + matrix[i + 1][9] + matrix[i][9] + matrix[i - 1][8] + matrix[i + 1][8]) / 5;
	}
	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 9; j++)
			smooth_matrix[i][j] = (matrix[i][j-1] + matrix[i][j+1] + matrix[i-1][j] + matrix[i-1][j-1] + matrix[i-1][j+1] + matrix[i+1][j] + matrix[i+1][j-1] + matrix[i+1][j+1]) / 8;
	
	cout << fixed << setprecision(2);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << setw(8) << smooth_matrix[i][j];
		cout << endl;
	}

	double sum=0;
	for (int i = 1; i < 10; i++) 
		for (int j = 0; j < i; j++) 
			sum += abs(smooth_matrix[i][j]);
	cout << "Сумма модулей элементов, расположенных ниже главной диагонали: " << sum << endl;
	return 0;
}

