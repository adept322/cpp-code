#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
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
			cout << "<Ошибка><Сумма на добавление отрицательна>" << endl;
		}
	}
	void WithdrawCash(double money_to_withdraw)
	{
		if (money_to_withdraw > 0)
		{
			if (money_to_withdraw > valid_cash && type != "credit")
			{
				cout << "<Ошибка><Недостаточно средств>" << endl;
			}
			else
			{
				valid_cash = valid_cash - money_to_withdraw;
				cout << "<Успешно>" << endl;
			}
		}
		else
		{
			cout << "<Ошибка><Сумма на снятие отрицательна>" << endl;
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
