#include "application.h"
#include "number.h"
#include "matrix.h"

using namespace std;
HANDLE Output = GetStdHandle(STD_OUTPUT_HANDLE);

Tapplication::Tapplication()
{


}
int Tapplication::exec()
{
	int select;
	Tmatrix matrix;
	int capacity;
	COORD cord{ 0,2 };
	
	while (true)
	{
		select = menu();
		switch (select)
		{
		case 49:
			system("cls");
			printf("fill in the capacity = ");
			cin >> capacity;
			number** arr;
			arr = new number * [capacity];
			for (int i = 0; i < capacity; i++) {
				arr[i] = new number[capacity];
			}
			cord.Y = 2;
			printf("fill in the matrix \n");
			for (int i = 0; i < capacity; i++) {
				for (int j = 0; j < capacity; j++) {
					SetConsoleCursorPosition(Output, cord);
					cin >> arr[i][j];
					cord.X += 5;
				}
				cord.Y += 1; cord.X = 0;
			}
			matrix.FillMatrix(capacity, arr);
			system("cls");
			break;
		case 50:
			system("cls");
			cord.Y = 7;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 3);
			cout << "Matrix's determinant: " << matrix.PrintDet() << endl;
			cord.Y += 1;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 15);
			cord = { 0,0 };
			SetConsoleCursorPosition(Output, cord);
			break;
		case 51:
			system("cls");
			cord.Y = 7;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 3);
			cout << "Here is your's matrix transposition: " << endl;
			cord.Y += 1;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 15);
			matrix.Transposition();
			matrix.PrintMatrix();
			cord = { 0,0 };
			SetConsoleCursorPosition(Output, cord);
			break;
			break;
		case 52:
		{
			system("cls");
			cord.Y = 7;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 3);
			cout << "Here is your rank:" << endl;
			cord.Y += 1;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 15);
			cout << matrix.rank();
			cord = { 0,0 };
			SetConsoleCursorPosition(Output, cord);

		}
		break;
		case 53:
		{
			system("cls");
			cord.Y = 7;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 3);
			cout << "Here is your matrix:" << endl;
			cord.Y += 1;
			SetConsoleCursorPosition(Output, cord);
			SetConsoleTextAttribute(Output, 15);
			matrix.PrintMatrix();
			cord = { 0,0 };
			SetConsoleCursorPosition(Output, cord);
		}
		break;
		case 27:
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
	SetConsoleTextAttribute(Output, 14);
	printf("1 - fill in matrix\n");
	printf("2 - find determinant\n");
	printf("3 - transpositioning\n");
	printf("4 - rank\n");
	printf("5 - print current matrix\n");
	SetConsoleTextAttribute(Output, 12);
	printf("esc - exit\n");
	SetConsoleTextAttribute(Output, 14);
	printf("_________________________________________________________________________________________________________________________________\n");
	int select = _getch();
	return select;

}