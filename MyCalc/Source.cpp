#include<iostream>
#include<Windows.h>
#include<string>
#include<vector>

#include"MyCalculator.h"

using namespace std;

int main()
{

	setlocale(LC_ALL, "Russian");
	string DATA = "";
	getline(cin, DATA);
	SmartCalc Example = SmartCalc(DATA);
	
	system("pause");
	return 0;
}