// matrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
void smooth(double** orig, double** smooth) {
	smooth[0][0] = (orig[0][0] + orig[0][1] + orig[1][0] + orig[1][1]) / 4;
	smooth[0][9] = (orig[0][9] + orig[0][8] + orig[1][9] + orig[1][8]) / 4;
	smooth[9][0] = (orig[9][0] + orig[8][0] + orig[9][1] + orig[8][1]) / 4;
	smooth[9][9] = (orig[9][9] + orig[9][8] + orig[8][9] + orig[8][8]) / 4;
	for (int i = 1; i < 9; i++) {
		smooth[0][i] = (orig[0][i] + orig[0][i - 1] + orig[0][i + 1] + orig[1][i] + orig[1][i - 1] + orig[1][i + 1]) / 6;
		smooth[9][i] = (orig[9][i] + orig[9][i - 1] + orig[9][i + 1] + orig[8][i] + orig[8][i - 1] + orig[8][i + 1]) / 6;
		smooth[i][0] = (orig[i][0] + orig[i - 1][0] + orig[i + 1][0] + orig[i][1] + orig[i - 1][1] + orig[i + 1][1]) / 6;
		smooth[i][9] = (orig[i][9] + orig[i - 1][9] + orig[i + 1][9] + orig[i][9] + orig[i - 1][8] + orig[i + 1][8]) / 6;
	}
	for (int i = 1; i < 9; i++)
		for (int j = 1; j < 9; j++)
			smooth[i][j] = (orig[i][j] + orig[i][j - 1] + orig[i][j + 1] + orig[i - 1][j] + orig[i - 1][j - 1] + orig[i - 1][j + 1] + orig[i + 1][j] + orig[i + 1][j - 1] + orig[i + 1][j + 1]) / 9;

}
double total(double** smooth) {
	double sum = 0;
	for (int i = 1; i < 10; i++)
		for (int j = 0; j < i; j++)
			sum += abs(smooth[i][j]);
	return sum;
}

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	cout << fixed << setprecision(2);
	cout << "начальная матрица: " << endl;
	double** matrix = new double *[10];
	for (int i = 0; i < 10; i++) {
		matrix[i] = new double[10];
		for (int j = 0; j < 10; j++) {
			matrix[i][j] = (rand() * 10) / (rand() + 0.1);
			cout << setw(8) << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;

	double** smooth_matrix = new double *[10];
	for (int i = 0; i < 10; i++)
		smooth_matrix[i] = new double[10];
	
	smooth(matrix, smooth_matrix);
	cout << "сглаженная матрица: " << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cout << setw(8) << smooth_matrix[i][j];
		cout << endl;
	}

	cout << endl;
	cout << "Сумма модулей элементов, расположенных ниже главной диагонали: " << total(smooth_matrix) << endl;
	return 0;
}
