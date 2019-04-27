#include <iostream>

using namespace std;

class Person
{
public:
	string name;
	int age;
	Person()
	{
		name = "";
		age = 0;
	}
};
class Female : public Person
{
public:
	int size;
	Female()
	{
		name = "";
		age = 0;
		size = 0;
	}
};
class Male : public Person
{
public:
	double length;
	Male()
	{
		name = "";
		age = 0;
		length = 0;
	}
};
template<typename TypeF, typename TypeS>
class Dance
{
public:
	TypeF First;
	TypeS Second;
	Dance()
	{
		First = NULL;
		Second = NULL;
	}
	Dance(TypeF f, TypeS s)
	{
		First = f;
		Second = s;
	}	
	void GoDance(TypeF f, TypeS s)
	{
		if (typeid(f).name() == typeid(s).name())
		{
			cout << "Error" << endl;
		}
		else
		{
			if (typeid(f).name() == "class Male" || typeid(f).name() == "Female")
			{
				if (typeid(s).name() == "Male" || typeid(s).name() == "Female")
				{
					cout << "Dancing" << endl;
				}
			}
		}

	}
};

int main()
{
	

	return 0;
}