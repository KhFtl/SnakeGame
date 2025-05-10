#include<iostream>
#include"Field.h"
#include<time.h>
using namespace std;
int main()
{
	srand(time(NULL));

	Field field;
	field.CreateBoundaries(wall_char);
	field.Show();
	cout << "Thanks for playing the Snake Game!" << endl;
	return 0;
}