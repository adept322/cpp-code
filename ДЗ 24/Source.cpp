#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
#include <Windows.h>
#include "BrendCheck.h"

using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	BrendCheck Brends = BrendCheck();
	Brends.ShowBrends();
	Brends.SaveBrends();
	system("pause");
	return 0;
}
