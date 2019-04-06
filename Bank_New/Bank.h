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
			cout << "Ошибка" << endl;
		}
	}
	~Bank()
	{
		Save();
	}
	void Show()
	{
		cout << left << setw(40) << "Name" << setw(7) << "Cash" << setw(11) << "ID " << setw(10) << "Type" << endl;
		for (int i = 0; i < base.size(); i++)
		{
			cout << left << setw(40) << base[i].GetName() << setw(7) << base[i].GetCash() << setw(11) << base[i].GetId() << setw(10) << base[i].GetType() << endl;
		}
	}
	void ShowMenu()
	{
		cout << endl;
		cout <<"<Банк>" <<endl;
		cout <<"<1><Открытие счета>" << endl;
		cout <<"<2><Удаление счета>" << endl;
		cout <<"<3><Сохранение данных>" << endl;
		cout <<"<4><Денежный перевод между обычными счетами>" << endl;
		cout <<"<5><Перевод с обычного счета на сберегательный и наоборот>" << endl;
		cout <<"<6><Cортировка по денежному счёту>" << endl;
		cout <<"<7><Cортировка по имени>" << endl;
		cout <<"<8><Группировка по типам вкладов>" << endl;
		cout <<"<9><Информация о счетах>" << endl;
		cout <<"<0><Выход>" << endl;
	}
	void AddAccount(BankAccount to_add)
	{
		bool match = true;
		for (int i = 0; i < base.size(); i++)
		{
			if (base[i].GetId() == to_add.GetId())
			{
				match = false;
				break;
			}
		}
		if (match == true && to_add.GetId().length() == 10)
		{
			base.push_back(to_add);
		}
		else
		{
			cout << "<Ошибка>" << endl;
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
	void SortName()
	{
		sort(base.begin(), base.end());
	}
	void SortSum()
	{
		for (int i = 1; i < base.size(); ++i)
		{
			for (int j = 0; j < base.size() - i; j++)
			{
				if (base[j].GetCash() < base[j + 1].GetCash())
				{
					swap(base[j], base[j + 1]);
				}
			}
		}
	}
	//трансфер не работает WHY???
	void Transfer(string from_id, string to_id, double sum)
	{
		int find_from = -1;
		int find_to= -1;
		for (int i = 0; i < base.size(); i++)
		{
			if (base[i].GetId() == from_id)
			{
				find_from = i;
			}
			if (base[i].GetId() == to_id)
			{
				find_to = i;
			}
		}
		if (find_from != -1 && find_to != -1 && base[find_from].GetType() != "deposit")
		{
			if (base[find_from].WithdrawCash(sum) == 0)
			{
				base[find_from].WithdrawCash(sum);
			}
			base[find_to].WithdrawCash(sum);
		}
		else
		{
			cout << "<Ошибка>" << endl;
		}
	}
};
