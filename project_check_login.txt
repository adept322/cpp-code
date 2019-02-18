#include <iostream>
#include <string>

using namespace std;

bool check_login(string login)
{
	bool check = true;
	int quantity_numbers = 0;
	for (int i = 0; i < login.length(); i++)
	{
		if (login[i] > 64 && login[i] < 91)
		{
			continue;
		}
		if(login[i] > 96 && login[i] < 123)
		{
			continue;
		}
		if (login[i] >= '0' && login[i] <= '9')
		{
			continue;
		}
		check = false;
	}
	
	return check;
}

int main()
{
	string login;
	while (true)
	{
	cin >> login;
	if (check_login(login) == true)
	{
		cout<<"Good"<<endl;
	}
	else
	{
		cout << "Bad" << endl;
	}
	}
	
	system("pause");
	return 0;
}