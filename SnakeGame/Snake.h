#pragma once
#include"GameHelper.h"

class Snake
{
	private:
		int length;
		//Position snakePos[1000];
		Position* snakePos;
		Rotation snakeRot;
	public:
		Snake(int _length, Rotation _snakeRot)
		{
			length = _length;
			snakeRot = _snakeRot;
			snakePos = new Position[1000];
		}
		void ToStartValues()
		{
			for (int i = 0; i < length; i++)
			{
				snakePos[i].x = 0;
				snakePos[i].y = 0;
			}
			length = 1;
			snakePos[0] = { x_max / 2, y_max / 2 };
			GameHelper::GoToXY(snakePos[0].x, snakePos[0].y);
			putchar(snake_head_char);
		}
		//Move keys - W, A, S, D
		void Move(char field[y_max][x_max + 1])
		{
			Sleep(100);
			if (GetAsyncKeyState('W'))
			{
				snakeRot = up;
			}
			else if (GetAsyncKeyState('S'))
			{
				snakeRot = down;
			}
			else if (GetAsyncKeyState('A'))
			{
				snakeRot = left;
			}
			else if (GetAsyncKeyState('D'))
			{
				snakeRot = right;
			}
			field[snakePos[length - 1].y][snakePos[length - 1].x] = ' ';
			for (int i = length; i > 0; i--)
			{
				snakePos[i] = snakePos[i - 1];
			}
			switch (snakeRot)
			{
				case up:
					snakePos[0].y = snakePos[0].y - 1;
					break;
				case down:
					snakePos[0].y = snakePos[0].y + 1;
					break;
				case left:
					snakePos[0].x = snakePos[0].x - 2;
					break;
				case right:
					snakePos[0].x = snakePos[0].x + 2;
					break; 
			}
			if (field[snakePos[0].y][snakePos[0].x] == price_char) AddTail();
			field[snakePos[0].y][snakePos[0].x] = snake_head_char;
			if (length > 1)
			{
				field[snakePos[1].y][snakePos[1].x] = snake_tail_char;
			}
		}
		void AddTail()
		{
			snakePos[length].x = snakePos[length - 1].x;
			snakePos[length].y = snakePos[length - 1].y;
			length++;
		}
		bool IsGameOver()
		{
			bool isGameOver = false;
			//Crash in wall
			if (snakePos[0].x <= 0 || snakePos[0].x >= x_max - 1 || snakePos[0].y <= 0 || snakePos[0].y >= y_max - 1)
			{
				isGameOver = true;
			}
			//Crash in snake tail
			for (int i = 2; i < length; i++)
			{
				if (snakePos[0].x == snakePos[i].x && snakePos[0].y == snakePos[i].y)
				{
					isGameOver = true;
					break;
				}
			}
			return isGameOver;
		}
		int GetLength()
		{
			return length;
		}
};