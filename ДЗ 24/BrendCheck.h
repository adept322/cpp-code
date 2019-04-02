#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

class BrendCheck
{
private:
	vector<string> array_of_brends;
	string current_brend;
public:
	BrendCheck()
	{
		ifstream fin;
		fin.open("input.txt");
		if (fin.is_open())
		{
			bool check = true;
			while (!fin.eof())
			{
				fin >> current_brend;
				for (int i = 0; i < current_brend.length(); i++)
				{
					while (current_brend[i] > 47 && current_brend[i] < 58)
					{
						current_brend.erase(current_brend.begin() + i);
					}

				}
				for (int i = 0; i < array_of_brends.size(); i++)
				{
					if (current_brend == array_of_brends[i])
					{
						check = false;
						break;
					}
				}
				if (check == true)
				{
					array_of_brends.push_back(current_brend);
				}
			}
		}
		else
		{
			current_brend = "error";
			cout << "<Error>" << endl;
		}
	}
	void SaveBrends()
	{
		ofstream fout;
		fout.open("output.txt");
		if (fout.is_open())
		{
			for (int i = 0; i < array_of_brends.size(); i++)
			{
				fout << array_of_brends[i] << endl;
			}
			fout.close();
			cout << "<Successfully>" << endl;
		}
		else
		{
			cout << "<Error>" << endl;
		}
	}
	void ShowBrends()
	{
		for (int i = 0; i < array_of_brends.size(); i++)
		{
			cout << array_of_brends[i] << endl;
		}
	}
};
