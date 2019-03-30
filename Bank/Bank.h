#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include "BankAccount.h"

using namespace std;

class Bank
{
private:
	vector<BankAccount> base;
public:
	Bank()
	{
		ifstream fin;
		fin.open("base.txt");
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				string _name;
				string _first, _second, _third;
				double _valid_cash;
				string _id_account;
				string _type;
				fin >> _first;
				fin >> _second;
				fin >> _third;
				_name = _first + " " + _second + " " + _third;
				fin >> _valid_cash;
				fin >> _id_account;
				fin >> _type;
				BankAccount buf = BankAccount(_name, _valid_cash, _id_account, _type);
				base.push_back(buf);
			}
			base.pop_back();
			fin.close();
		}
		else
		{
			cout << "Îøèáêà" << endl;
		}
	}
	void Show()
	{
		cout << left << setw(40) << "Name" << setw(7) << "Cash" << setw(11) << "ID " << setw(10) << "Type" << endl;
		for (int i = 0; i < base.size(); i++)
		{
			cout << left << setw(40) << base[i].GetName() << setw(7) << base[i].GetCash() << setw(11) << base[i].GetId() << setw(10) << base[i].GetType() << endl;
		}
	}
	void AddAccount(BankAccount to_add)
	{
		bool check = true;
		for (int i = 0; i < base.size(); i++)
		{
			if (base[i].GetId() == to_add.GetId())
			{
				check = false;
				break;
			}
		}
		if (check == true && to_add.GetId().length() == 10)
		{
			base.push_back(to_add);
		}
		else
		{
			cout << "Îøèáêà" << endl;
		}
	}
	void RemoveAccount(string ID)
	{
		for (int i = 0; i < base.size(); i++)
		{
			if (base[i].GetId() == ID)
			{
				base.erase(base.begin() + i);
			}
		}
	}
	void Save()
	{
		ofstream fout;
		fout.open("base.txt");
		for (int i = 0; i < base.size(); i++)
		{
			fout << base[i].GetName() << " " << base[i].GetCash() << " " << base[i].GetId() << " " << base[i].GetType()<< endl;
		}
		fout.close();
	}
};