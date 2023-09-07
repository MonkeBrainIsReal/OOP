#include "application.h"
#include "number.h"
#include "matrix.h"
#include <iostream>
#include <conio.h>
using namespace std;

Tapplication::Tapplication() 
{


}
int Tapplication::exec() 
{
	int select;
	number a[3][3] = 
	{
		{1,1,1},
		{1,1,1},
		{1,1,1}

	};//матрица по умолчанию
	while (true) 
	{
		select = menu();
		switch (select) 
		{
		case 49:
			system("cls");
			cout << "1\n";
			break;
		case 50:
			system("cls");
			cout << "2\n";
			break;
		case 51:
			system("cls");
			cout << "3\n";
			break;
		case 52: 
		{
			system("cls");
			cout << "4\n";
			Tmatrix a();
			
		}
			
			break;
		case 53:
			system("cls");
			cout << "5\n";
			break;
		case 48:
			system("cls");
			cout << "0\n";
				return 0;
		default:
			break;

		}
	}
}

int Tapplication::menu() 
{

	int select = _getch();
	printf("1 - fill in the matrix\n");
	printf("2 - determinant\n");
	printf("3 - transpositioning\n");
	printf("4 - rang\n");
	printf("5 - print current matrix\n");
	printf("0 - exit\n");
	return select;

}