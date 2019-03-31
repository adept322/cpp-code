#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include "Labirint.h"

using namespace std;

int main()
{
	SetConsoleOutputCP;
	Labirint Lab = Labirint();
	int level = 0;
	int score = 0;
	while (Lab.GetEnd()!=true)
	{
		level = Lab.GetLevel();
		score = Lab.GetScore();
		system("cls");
		cout << "Level-> " << ++level << endl;
		Lab.ShowMap();
		cout << "Score: " << ++score << endl;
		int key = _getch();
		string direction = " ";
		if (key == 72 || key == 150 || key == 230)
		{
			direction = "up";
		}	
		if (key == 80 || key == 155 || key == 235)
		{
			direction = "down";
		}	
		if (key == 77 || key == 130 || key == 262)
		{
			direction = "left";
		}
		if (key == 75 || key == 148 || key == 235)
		{
			direction = "right";
		}	
		Lab.Move(direction);
	}


	system("pause");
	return 0;
}