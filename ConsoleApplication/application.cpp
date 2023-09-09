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
	number capacity = 3, coloumns_f = 3;
	Tmatrix matrix;
	while (true)
	{
		select = menu();
		switch (select)
		{
		case 49://done

			matrix.FillMatrix();
			break;
		case 50:
			system("cls");
			matrix.PrintDet();
			break;


		case 51:
			system("cls");
			cout << "3\n";
			break;
		case 52:
		{
			system("cls");
			cout << "4\n";
		}
		break;
		case 53://done
		{
			system("cls");
			cout << "Here is your matrix:" << endl;
			matrix.PrintMatrix();
		}
		break;
		case 27://done
			system("cls");
			cout << "Good bye\n";
			return 0;
			break;
		default:
			break;
		}
	}
}

int Tapplication::menu()
{
	printf("1 - fill in matrix\n");
	printf("2 - determinant\n");
	printf("3 - transpositioning\n");
	printf("4 - rang\n");
	printf("5 - print current matrix\n");
	printf("esc - exit\n");
	int select = _getch();
	return select;

}