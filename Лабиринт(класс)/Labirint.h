#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <fstream>
class Labirint
{
private:
	int map[3][5][5];
	int level;
	int current_i;
	int current_j;
	int score;
	bool enemy;
	bool end;
	void FindStart()
	{
		current_i = 0;
		current_j = 0;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (map[level][i][j] == 2)
				{
					current_i = i;
					current_j = j;
					break;
				}
			}
		}
	}
public:
	Labirint()
	{
		enemy == false;
		current_i = 0;
		current_j = 0;

		level = 0;
		score = 0;
		end = false;
		ifstream fin;
		fin.open("map.txt");
		if (fin.is_open())
		{
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					for (int k = 0; k < 5; k++)
					{
						fin >> map[i][j][k];
					}
				}
			}
			fin.close();
			FindStart();
		}
		else
		{
			return 0;
		}
	}
	void ShowMap()
	{

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (map[level][i][j] == 1)
				{
					cout << static_cast<char>(177);
					cout << static_cast<char>(177);
				}
				if (map[level][i][j] == 2)
				{
					cout << static_cast<char>(178);
					cout << static_cast<char>(178);
				}
				if (map[level][i][j] == 3)
				{
					cout << static_cast<char>(36);
					cout << static_cast<char>(36);
				}
				if (map[level][i][j] == 4)
				{

					cout << "##";
				}
				if (map[level][i][j] == 0)
				{
					cout << "  ";
				}
			}
			cout << endl;
		}
	}
	void Move(string direction)
	{

		if (direction == "up")
		{
			if (current_i > 0 && map[level][current_i - 1][current_j] != 1)
				current_i = current_i - 1;
		}
		if (direction == "down")
		{
			if (current_i < 4 && map[level][current_i + 1][current_j] != 1)
				current_i = current_i + 1;
		}
		if (direction == "right")
		{
			if (current_j > 0 && map[level][current_i][current_j + 1] != 1)
				current_j = current_j - 1;
		}
		if (direction == "left")
		{
			if (current_j < 4 && map[level][current_i][current_j + 1] != 1)
				current_j = current_j + 1;
		}
		if (map[level][current_i][current_j] == 3)
		{
			score++;
		}
		if (map[level][current_i][current_j] == 5)
		{
			cout << "@GameOver@" << endl;
			end == true;
		}
		if (map[level][current_i][current_j] == 4)
		{
			level++;
			if (level == 3)
			{
				end = true;
			}
			FindStart();
		}
		map[level][current_i][current_j] = 2;

	}
	int GetLevel()
	{
		return level;
	}
	bool GetEnd()
	{
		return end;
	}
	int GetScore()
	{
		return score;
	}
	void SetEnemy()
	{
		enemy = true;
	}
};
