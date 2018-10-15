// arraysandmatrices.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

struct point {
	int x;
	int y;
};

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Rus");
	cout << "Дано 3n точек, введите n: ";
	int n;
	cin >> n;
	int cnt = 3 * n;
	point  *arr = new point[cnt];
	for (int i = 0; i < cnt; i++) {
		cout << i + 1 << "";
		cout << "";
		cin >> arr[i].x;
		cout << "";
		cin >> arr[i].y;
	}
	double min_len = sqrt(pow(arr[1].x, 2) + pow(arr[1].y, 2));
	for (int i = 0; i < cnt; i++)
		if (sqrt(pow(arr[i].x, 2) + pow(arr[i].y, 2)) < min_len)
			min_len = sqrt(pow(arr[i].x, 2) + pow(arr[i].y, 2));

	double **triangles = new double*[cnt];
	for (int i = 0; i < cnt; i++)
		triangles[cnt] = new double[3];



	return 0;
}

