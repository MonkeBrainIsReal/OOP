#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include "number.h"
#include <iomanip>
#include <ostream>

using namespace std;


class Tmatrix
{
public:
	Tmatrix();
	void FillMatrix();
	void PrintMatrix();
	number PrintDet();
	void Transposition();
	int rank();
private:
	number** arr;
	int capacity = 3;
	void fillWithZeros(number matrix[10][10]);
	number determinant(number matrix[10][10], int capacity);
};

#endif // !MATRIX_H