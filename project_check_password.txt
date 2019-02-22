 #include <iostream>
#include <string>

using namespace std;

bool check_password(string password)
{
	int quantity_numbers = 0;
	int big_registr = 0, small_registr = 0;
	bool check = true;
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] == '1' || password[i] == '2' || password[i] == '3')
		{
			quantity_numbers++;
		}
		if (password[i] == '4' || password[i] == '5' || password[i] == '6')
		{
			quantity_numbers++;
		}
		if (password[i] == '7' || password[i] == '8' || password[i] == '9')
		{
			quantity_numbers++;
		}
		if (password[i] == '0')
		{
			quantity_numbers++;
		}
	}
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] > 64 && password[i] < 91)
		{
			big_registr++;
		}
		if (password[i] > 96 && password[i] < 123)
		{
			small_registr++;
		}
	}
	if (quantity_numbers == 0)
	{
		check = false;
	}
	if (small_registr == 0 || big_registr == 0)
	{
		check = false;
	}
	if (password.length() < 8)
	{
		check = false;
	}
	if (password.length() > 16)
	{
		check = false;
	}
	return check;
}

int main()
{
	string text;
	while (true)
	{
		cin >> text;
		if (check_password(text) == true)
		{
			cout << "Good" << endl;
		}
		if (check_password(text) == false)
		{
			cout << "Bad " << endl;
		}
	}
	system("pause");
	return 0;
}
