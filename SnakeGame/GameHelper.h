#pragma once
#include<iostream>
#include<windows.h>
#include<stdlib.h>

//Field size constatnts
const int x_max = 100;
const int y_max = 25;
//Game chars constants
const char snake_head_char = 'O';
const char wall_char = char(219);// '#';
const char price_char = '$';
const char snake_tail_char = '*';


enum Rotation
{
	left,
	right,
	up,
	down
};

struct Position
{
	int x;
	int y;
};

class GameHelper
{
	public:
		static void GoToXY(int x, int y)
		{
			COORD pos = { x, y };
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(handle, pos);
		}
		static void CursorVisible(bool visible)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_CURSOR_INFO cursorInfo;
			GetConsoleCursorInfo(handle, &cursorInfo);
			cursorInfo.bVisible = visible;
			SetConsoleCursorInfo(handle, &cursorInfo);
		}
};