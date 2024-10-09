#include<iostream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

//розміри поля
const int x_max = 118;
const int y_max = 28;
//Переміщення курсору на позицію x y
void GoToXY(int x, int y)
{
	COORD pos = { x,y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
}
//Видимість курсора
void CursorVisible(bool visible)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = visible;
	SetConsoleCursorInfo(handle, &structCursorInfo);
}

//Напрямки руху змії
enum Rotation
{
	left,
	right,
	up,
	down
};

struct Position
{
	int x; int y;
};
class Field
{
public:
	char field[y_max][x_max + 1];
	void CreateBoundaries(char ch);//Створення границі гри
	void Show();
	void SpownPrice();
};
//Реалізація методів класу Field
void Field::CreateBoundaries(char ch)
{
	for (int y = 0; y < y_max; y++)
	{
		for (int x = 0; x < x_max; x++)
		{
			if (y == 0 || y == y_max - 1 || x == 0 || x == x_max - 1) 
			{
				field[y][x] = ch;
			}
			else
			{
				field[y][x] = ' ';
			}
		}
		field[y][x_max] = '\0';//перхід на новий рядок
	}
}

void Field::Show()
{
	GoToXY(0, 0);
	for (int y = 0; y < y_max; y++)
	{
		cout << field[y] << endl;
	}
}

void Field::SpownPrice()
{
}

int main()
{
	Field gameField;
	gameField.CreateBoundaries(219);
	gameField.Show();
	getchar();
	//return 0;
}