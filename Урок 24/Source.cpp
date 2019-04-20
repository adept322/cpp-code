#include <iostream>
#include <string>
#include "VectorHeader.h"

using namespace std;

int main()
{
	Vector Arr = Vector(6,3);
	Arr.VShowAllElements();
	Arr[2] = 2;
	Arr.VShowAllElements();
	Arr.VInsertElementbyIndex(2,4);
	Arr.VShowAllElements();
	Arr.VInsertElementbyIndex(2, 5);
	Arr.VShowAllElements();
	system("pause");
	return 0;
}