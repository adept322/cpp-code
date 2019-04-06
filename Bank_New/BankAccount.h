#pragma once
#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
protected:
	string name;
	double valid_cash;
	string id_account;
	string type;
public:
	BankAccount()
	{
		name = "";
		valid_cash = 0;
		id_account = "";
		type = "";
	}
	BankAccount(string name, double valid_cash,string id_account,string type)
	{
		this->name = name;
		this->valid_cash = valid_cash;
		this->id_account = id_account;
		this->type = type;
	}
	void AddCash(double money_to_add)
	{
		if (money_to_add > 0)
		{
			valid_cash = valid_cash + money_to_add;
			cout << "<Успешно>" << endl;
		}
		else
		{
			cout << "<Ошибка>" << endl;
		}
	}
	int WithdrawCash(double money_to_withdraw)
	{
		if (money_to_withdraw > 0)
		{
			if (money_to_withdraw > valid_cash && type != "credit")
			{
				cout << "<Ошибка>" << endl;
				return -1;
			}
			else
			{
				valid_cash = valid_cash - money_to_withdraw;
				cout << "<Успешно>" << endl;
				return 0;
			}
		}
		else
		{
			cout << "<Ошибка>" << endl;
			return -2;
		}
	}
	string GetName()
	{
		return name;
	}
	double GetCash()
	{
		return valid_cash;
	}
	string GetId()
	{
		return id_account;
	}
	string GetType()
	{
		return type;
	}
};
