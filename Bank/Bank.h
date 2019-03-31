#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
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
			fin.close();
			base.pop_back();
		}
		else
		{
			cout << "<Ошибка><Чтение базы невозможно>" << endl;
		}
	}
	void Show()
	{
		cout << left << setw(40) << "Name(FIO)" << setw(10) << "Money($)" << setw(11) << "ID(10)" << setw(10) << "Type(DDC)" << endl;
		for (int i = 0; i < base.size(); i++)
		{
			cout << left << setw(40) << base[i].GetName() << setw(10) << base[i].GetCash() << setw(11) << base[i].GetId() << setw(10) << base[i].GetType() << endl;
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
		if(to_add.GetCash() < 0 && to_add.GetType() != "credit")
		{
			cout<<"<Ошибка><Некорректный баланс>"<<endl;
		}
		else
		{
			if (check == true && to_add.GetId().length() == 10)
			{
				base.push_back(to_add);
			}
			else
			{
				cout << "<Ошибка><ID занят><Некорректный ID>" << endl;
			}		
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
	int SizeBase()
	{
		return base.size();
	}
	void AddCashToAccount(double _cash,string _id)
	{
		bool add = false;
		for (int i = 0; i < base.size(); i++)
		{
			if (base[i].GetId() == _id)
			{
				base[i].AddCash(_cash);
				add = true;
				break;
			}
		}
	}
	void WithdrawCashToAccount(double _cash, string _id)
	{
		bool del = false;
		for (int i = 0; i < base.size(); i++)
		{
			if (base[i].GetId() == _id)
			{
				base[i].WithdrawCash(_cash);
				del = true;
				break;
			}
			if (del == true && i - 1 == base.size())
			{
				cout << "<Ошибка><Некорректный ID>" << endl;
			}
		}
	}
};