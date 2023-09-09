#include <Windows.h>
#include "matrix.h"
#include <iostream>
#include<math.h>
HANDLE Output = GetStdHandle(STD_OUTPUT_HANDLE);
//COORD crd = { 1600,900 };
//HWND hWindowConsole = GetConsoleWindow();
using namespace std;
Tmatrix::Tmatrix() {
	arr = new number * [capacity];
	for (int i = 0; i < capacity; i++) {
		arr[i] = new number[capacity];
	}
	for (int i = 0; i < capacity; i++) {
		for (int j = 0; j < capacity; j++) {
			arr[i][j] = 0;
		}
	}
}
void Tmatrix::FillMatrix()
{
	
	system("cls");
	printf("fill in the capacity = ");
	cin >> capacity;
	arr = new number * [capacity];
	for (int i = 0; i < capacity; i++) {
		arr[i] = new number[capacity];
	}
	COORD cord{ 0,2 };

	printf("fill in the matrix \n");
	for (int i = 0; i < capacity; i++) {
		for (int j = 0; j < capacity; j++) {
			SetConsoleCursorPosition(Output, cord);
			cin >> arr[i][j];
			cord.X += 5;
		}
		cord.Y += 1; cord.X = 0;
	}
	system("cls");
}

void Tmatrix::PrintMatrix() {
	cout << "Here is your matrix:" << std::endl;
	for (int i = 0; i < capacity; i++) {
		for (int j = 0; j < capacity; j++) {
			cout << arr[i][j] << " ";
		}
		cout << std::endl;
	}
}

void Tmatrix::PrintDet() {
	number submatrix[10][10];
	fillWithZeros(submatrix);
	for (int i = 0; i < capacity; i++) {
		for (int j = 0; j < capacity; j++) {
			submatrix[i][j] = arr[i][j];
		}

	}
	cout << determinant(submatrix, capacity) << endl;
}
void Tmatrix::fillWithZeros(number massiv[10][10]) {
	for (int i = 0; i < capacity; ++i) {
		for (int j = 0; j < capacity; ++j) {
			massiv[i][j] = 0;
		}
	}
}
number Tmatrix::determinant(number matrix[10][10], int n) {
	number det = 0;
	number submatrix[10][10];
	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
		}
	}
	cout << det << endl;
	return det;
}