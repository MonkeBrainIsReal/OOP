#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include "number.h"
#include <ostream>
using namespace std;


class Tmatrix
{
	//number capacity, coloumns_f;
public:
	Tmatrix();
	void FillMatrix();
	void PrintMatrix();
	void PrintDet();


	//friend ostream& operator<<(ostream&, Tmatrix&);
private:
	number** arr;
	void fillWithZeros(number massiv[10][10]);
	int capacity = 2;
	number determinant(number submatrix[10][10], int capacity);
};

#endif // !MATRIX_H