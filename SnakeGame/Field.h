#pragma once
#include"GameHelper.h"

class Field
{
	public:
		char field[y_max][x_max + 1];
		void CreateBoundaries(char ch)
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
				field[y][x_max] = '\0';
			}
		}
		void Show()
		{
			GameHelper::GoToXY(0, 0);
			for (int y = 0; y < y_max; y++)
			{
				std::cout << field[y] << std::endl;
			}
		}
		void SpownPrice()
		{
			int x = rand() % (x_max - 2) + 1;
			int y = rand() % (y_max - 2) + 1;
			bool isSpown = false;
			while (true)
			{
				if (x % 2 == 0) isSpown = true;
				if (field[y][x] == snake_head_char || field[y][x] == wall_char) isSpown = false;
				if (isSpown) break;
				x = rand() % (x_max - 2) + 1;
			}
			field[y][x] = price_char;
		}
};