#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "Bank.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int answer = 0;
	Bank Test = Bank();
	while(true)
	{ 
		system("cls");
		Test.Show();
		cout << endl;
		Test.ShowMenu();
		cin >> answer;
		switch (answer)
		{
		case 1:
		{
			int answ = 0;
			string name;
			double valid_cash;
			string id_account;
			string type;
			string f, i, o;
			cout << "<¬ведите фамилию>" << endl;
			cin >> f;
			cout << "<¬ведите им€>" << endl;
			cin >> i;
			cout << "<¬ведите отчество>" << endl;
			cin >> o;
			name = f + " " + i + " " + o;
			cout << "<¬ведите сумму денег>" << endl;
			cin >> valid_cash;
			cout << "<¬ведите Id>" << endl;
			cin >> id_account;
			cout << "<¬ведите тип аккаунта(1 - debit)(2 - deposit)(3 - credit)>" << endl;
			cin >> answ;
			if (answ == 1)
				type = "debit";
			if (answ == 2)
				type = "deposit";
			if (answ == 3)
				type = "credit";
			BankAccount to_add = BankAccount(name,valid_cash,id_account,type);
			Test.AddAccount(to_add);
			break;
		}
		case 2:
		{
			string delete_id;
			cout << "<¬ведите Id(10)>" << endl;
			cin >> delete_id;
			Test.RemoveAccount(delete_id);
			break;
		}
		case 3:
		{
			Test.Save();
			cout << "<”спешно>" << endl;
			system("pause");
			break;
		}
		case 4:
		{
			//на стадии разработки
			//не робит
			string from_id, to_id;
			double transfer;
			cout << "<¬ведите Id отправител€>" << endl;
			cin >> from_id;
			cout << "<¬ведите Id получател€>" << endl;
			cin >> from_id;
			cout << "<¬ведите сумму денег>" << endl;
			cin >> transfer;
			Test.Transfer(from_id, to_id, transfer);
			break;
		}
		case 5:
		{
			//на стадии разработки
		}
		case 6:
		{
			Test.SortSum();
			break;
		}
		case 7:
		{
			Test.SortName();
			break;
		}
		case 0:
		{
			cout << "<¬ыход>" << endl;
			system("pause");
			return 0;
		}
		default:
		{

		}
		}
	}
	system("pause");
	return 0;
}