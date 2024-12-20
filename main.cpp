#include "user.h"
#include <map>
#include <iostream>
#include "deposit.h"
#include "product.h"
#include <windows.h>
#include<cstdlib>
#include "inventory.h"

using namespace std;

int main()
{
	string email, password;
	do {
		cout << "Email: ";
		cin >> email;
		cout << "Password: ";
		cin >> password;

		map<string, string >utilizator_temp = User::get_user(email, password);

		if (utilizator_temp["email"] == email && utilizator_temp["password"] == password)
		{
			User utilizator(utilizator_temp["name"], utilizator_temp["first_name"], utilizator_temp["email"], utilizator_temp["password"]);

			cout << "\nWelcome, " << utilizator.get_name() << " " << utilizator.get_first_name() << "!\n" << endl;
			Sleep(3000);
			break;
		}
		else
		{
			cout << "Email or password are wrong!\n" << endl;

			system("pause");
			system("cls");
		}
	} while (true);

	system("cls");

	int ok_1 = 1;

	while (ok_1)
	{
		cout << "----MENU----\n" << endl;
		cout << "1. Add deposit" << endl;
		cout << "2. Print deposits" << endl;
		cout << "3. Select deposit" << endl;
		cout << "4. Delete deposit" << endl;
		cout << "5. Exit\n" << endl;
		cout << "Option: ";
		int option = 0;
		cin >> option;
		system("cls");
		switch (option)
		{
		case 1:
		{
			string name;
			string address;
			cout << "Deposit name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Deposit Address: ";
			getline(cin, address);
			Deposit::add_deposit(name, address);
			system("pause");
			system("cls");
			break;
		}

		case 2:
		{
			Deposit::print_deposits();
			cout << "\n";
			system("pause");
			system("cls");
			break;
		}

		case 3:
		{
			string name;
			cout << "Deposit name: ";
			cin.ignore();
			getline(cin, name);

			Deposit deposit = Deposit::select_deposit(name);
			if (deposit.get_name() == "" || deposit.get_address() == "")
			{
				system("pause");
				system("cls");
				break;
			}
			Sleep(3000);
			system("cls");
			int ok_2 = 1;
			while (ok_2)
			{
				cout << "----MENU----\n" << endl;
				cout << "1. Add product" << endl;
				cout << "2. Delete product" << endl;
				cout << "3. Print inventory" << endl;
				cout << "4. Ceck stock" << endl;
				cout << "5. Edit product" << endl;
				cout << "6. Return to main menu" << endl;

				cout << "\nOption: ";
				int op = 0;
				cin >> op;
				system("cls");
				switch (op)
				{
				case 1:
				{
					string name;
					float price;
					int quantity;
					cout << "Product name: ";
					cin.ignore();
					getline(cin, name);
					cout << "Product price: ";
					cin >> price;
					cout << "Product quantity: ";
					cin >> quantity;
					Inventory::add_product(deposit.get_name(), name, price, quantity);
					system("pause");
					system("cls");
					break;
				}
				case 2:
				{
					string name;
					cout << "Product name: ";
					cin.ignore();
					getline(cin, name);
					Product::delete_product(deposit.get_name(), name);
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					Inventory::print_inventory(deposit.get_name());
					system("pause");
					system("cls");
					break;
				}
				case 4:
				{
					Inventory::check_stock(deposit.get_name());
					system("pause");
					system("cls");
					break;
				}
				case 5:
				{
					int ok_3 = 1;
					int opt = 0;

					while (ok_3)
					{
						cout << "---Menu---\n" << endl;
						cout << "1.Set a new price\n" << endl;
						cout << "2.Set a new quantity\n" << endl;
						cout << "3.Return to main menu\n" << endl;
						cout << "Option:";
						cin >> opt;
						system("cls");
						switch (opt)
						{
						case 1:
						{
							string name;
							cout << "Product name: ";
							cin.ignore();
							getline(cin, name);
							cout << endl;
							cout << "New price: ";
							float new_price;
							cin >> new_price;
							Product::editing_the_product_price(deposit.get_name(), name, new_price);
							system("pause");
							system("cls");
							break;
						}
						case 2:
						{
							string name;
							cout << "Product name: ";
							cin.ignore();
							getline(cin, name);
							cout << endl;
							cout << "New quantity: ";
							int new_quantity;
							cin >> new_quantity;
							Product::editing_the_product_quantity(deposit.get_name(), name, new_quantity);
							system("pause");
							system("cls");
							break;
						}
						case 3:
						{
							ok_3 = 0;
							system("cls");
							break;
						}
						default:
						{
							cout << "Invalid option!\n" << endl;
							Sleep(3000);
							system("cls");
							break;
						}
						}
					}
					system("pause");
					system("cls");
					break;
				}
				case 6:
				{
					ok_2 = 0;
					system("cls");
					break;
				}
				default:
				{
					cout << "Invalid option!\n" << endl;
					Sleep(3000);
					system("cls");
					break;
				}
				}
			}
			system("cls");
			break;
		}

		case 4:
		{
			string name;
			cout << "Deposit name: ";
			cin.ignore();
			getline(cin, name);
			Deposit::delete_deposit(name);
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			ok_1 = 0;
			break;
		}
		default:
			cout << "Invalid option!\n" << endl;
			Sleep(3000);
			system("cls");
			break;
		}
	}
}