#include<iostream>
#include"Field.h"
#include"Snake.h"
#include<time.h>
using namespace std;
int main()
{
	srand(time(NULL));
	GameHelper::CursorVisible(false);
	Field field;
	Snake snake(1, up);
	field.CreateBoundaries(wall_char);
	snake.ToStartValues();

	int sleepTime = 100;

	for (int i = 0; i < 20; i++)
	{
		field.SpownPrice();
	}
	while (true)
	{
		if (snake.IsGameOver()) break;
		snake.Move(field.field);
		field.Show();
		sleepTime = abs(sleepTime - snake.GetLength() * 5);
		Sleep(sleepTime);
	}
	GameHelper::CursorVisible(true);
	cout << "Thanks for playing the Snake Game!" << endl;
	//getchar();
	return 0;
}