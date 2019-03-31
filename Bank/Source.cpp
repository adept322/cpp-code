#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <Windows.h>
#include "Bank.h"

using namespace std;

void PrintMenu()
{
	cout << "<1><Сохранить базу>" << endl;
	cout << "<2><Открыть счёт>" << endl;
	cout << "<3><Удалить счёт(ID)>" << endl;
	cout << "<4><Пополнить счёт(ID)>" << endl;
	cout << "<5><Снять деньги со счёта(ID)>" << endl;
	cout << "<0><Выход>" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int answer = -1;
	Bank Database;
	cout << "<База создана>" << endl;
	while (answer != 0)
	{
		system("cls");
		Database.Show();
		cout << endl;
		PrintMenu();
		cin >> answer;
		switch (answer)
		{
		case 1:
		{
			Database.Save();
			cout << "<Успешно>" << endl;
			break;
		}
		case 2:
		{
			int answ_type = 0;
			string _name;
			double _valid_cash;
			string _id_account;
			string _type;
			string _first, _second, _third;
			cout <<"<Введите Имя>"<< endl;
			cin >> _first;
			cout << "<Введите Фамилию>" << endl;
			cin >> _second;
			cout << "<Введите Отчество>" << endl;
			cin >> _third;
			_name = _first + " " + _second + " " + _third;
			cout << "<Введите Id><10 цифр>" << endl;
			cin >> _id_account;
			cout << "<Введите Средства>" << endl;
			cin >> _valid_cash;
			cout << "<Введите Тип><1->Депозитная><2->Дебютовая><3->Кредитная>" << endl;
			cin >> answ_type;
			if (answ_type == 1)
				_type = "deposit";
			if (answ_type == 2)
				_type = "debit";
			if (answ_type == 3)
				_type = "credit";
			BankAccount add = BankAccount(_name, _valid_cash, _id_account, _type);
			Database.AddAccount(add);
			break;
		}
		case 3:
		{
			string delete_id = "";
			cout << "<Введите ID>" << endl;
			cin >> delete_id;
			Database.RemoveAccount(delete_id);
			cout << "<Успешно>" << endl;
			break;
		}
		case 4:
		{
			string _id = "";
			double _sum = 0;
			cout << "<Введите ID>" << endl;
			cin >> _id;
			cout << "<Введите сумму>" << endl;
			cin >> _sum;
			Database.AddCashToAccount(_sum,_id);
			break;
		}
		case 5:
		{
			string _id = "";
			double _sum = 0;
			cout << "<Введите ID>" << endl;
			cin >> _id;
			cout << "<Введите сумму>" << endl;
			cin >> _sum;
			Database.WithdrawCashToAccount(_sum, _id);
			break;
		}
		case 0:
		{
			char symbol = ' ';
			while (true)
			{
				
				system("cls");
				cout << "<Сохранить изменения в файл(Y/N)>" << endl;
				cin >> symbol;
				if (symbol == 'Y' || symbol == 'y')
				{
					Database.Save();
					cout << "<Успешно>" << endl;
					break;
				}
				else
				{
					if (symbol == 'N' || symbol == 'n')
					{
						cout << "<Выход>" << endl;
						break;
					}
					else
					{
						cout << "<Ошибка>" << endl;
					}
				}
				system("pause");
			}
		}
		default:
		{
			continue;
		}
		}
		system("pause");
	}
	system("pause");
	return 0;
}