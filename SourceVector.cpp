#include <iostream>
#include <string>
#include "VectorHeader.h"

using namespace std;

int main()
{
	Vector<double> Arr;
	Arr.VAddNewElement(1.53324);
	Arr.VAddNewElement(1.52321324);
	Arr.VAddNewElement(1.5523524);
	Arr.VShowAllElements();
	Arr.VRemoveLastElement();
	Arr.VShowAllElements();
	system("pause");
	return 0;
}