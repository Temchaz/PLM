// matrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	double matrix[10][10] = {
		{1,2,3,4,5,6,7,8,9,10},
		{11,12,13,14,15,16,17,18,19,20},
		{21,22,23,24,25,26,27,28,29,30},
		{31,32,33,34,35,36,37,38,39,40},
		{41,42,43,44,45,46,47,48,49,50},
		{51,52,53,54,55,56,57,58,59,60},
		{61,62,63,64,65,66,67,68,69,70},
		{71,72,73,74,75,76,77,78,79,80},
		{81,82,83,84,85,86,87,88,89,90},
		{91,92,93,94,95,96,97,98,99,100},
	};
	double smooth_matrix[10][10];
	smooth_matrix[0][0] = (matrix[0][0] + matrix[0][1] + matrix[1][0] + matrix[1][1]) / 4;
	smooth_matrix[0][9] = (matrix[0][9] + matrix[0][8] + matrix[1][9] + matrix[1][8]) / 4;
	smooth_matrix[9][0] = (matrix[9][0] + matrix[8][0] + matrix[9][1] + matrix[8][1]) / 4;
	smooth_matrix[9][9] = (matrix[9][9] + matrix[9][8] + matrix[8][9] + matrix[8][8]) / 4;
	for (int i = 1; i < 9; i++) {
		smooth_matrix[0][i] = (matrix[0][i] + matrix[0][i - 1] + matrix[0][i + 1] + matrix[1][i] + matrix[1][i - 1] + matrix[1][i + 1]) / 6;
		smooth_matrix[9][i] = (matrix[9][i] + matrix[9][i - 1] + matrix[9][i + 1] + matrix[8][i] + matrix[8][i - 1] + matrix[8][i + 1]) / 6;
		smooth_matrix[i][0] = (matrix[i][0] + matrix[i - 1][0] + matrix[i + 1][0] + matrix[i][1] + matrix[i - 1][1] + matrix[i + 1][1]) / 6;
		smooth_matrix[i][9] = (matrix[i][9] + matrix[i - 1][9] + matrix[i + 1][9] + matrix[i][9] + matrix[i - 1][8] + matrix[i + 1][8]) / 6;
	}
	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 9; j++)
			smooth_matrix[i][j] = (matrix[i][j] + matrix[i][j-1] + matrix[i][j+1] + matrix[i-1][j] + matrix[i-1][j-1] + matrix[i-1][j+1] + matrix[i+1][j] + matrix[i+1][j-1] + matrix[i+1][j+1]) / 9;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << smooth_matrix[i][j]<<", ";
		cout << endl;
	}
	return 0;
}

