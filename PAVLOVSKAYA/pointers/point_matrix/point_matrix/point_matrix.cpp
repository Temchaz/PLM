// matrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	cout << fixed << setprecision(2);
	cout << "исходная матрица: " << endl;
	double **matrix = new double *[10];
	for (int i = 0; i < 10; i++) {
		matrix[i] = new double[10];
		for (int j = 0; j < 10; j++) {
			matrix[i][j] = (rand()*10)/(rand()+0.1);
			cout << setw(8) << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
	double** smooth_matrix = new double *[10];
	for (int i = 0; i < 10; i++)
		smooth_matrix[i] = new double[10];
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
			smooth_matrix[i][j] = (matrix[i][j] + matrix[i][j - 1] + matrix[i][j + 1] + matrix[i - 1][j] + matrix[i - 1][j - 1] + matrix[i - 1][j + 1] + matrix[i + 1][j] + matrix[i + 1][j - 1] + matrix[i + 1][j + 1]) / 9;

	cout << "сглаженная матрица: " << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << setw(8) << smooth_matrix[i][j];
		cout << endl;
	}

	double sum = 0;
	for (int i = 1; i < 10; i++)
		for (int j = 0; j < i; j++)
			sum += abs(smooth_matrix[i][j]);
	cout << "Сумма модулей элементов, расположенных ниже главной диагонали: " << sum << endl;
	return 0;
}


