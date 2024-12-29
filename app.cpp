#include "app.h"
#include <windows.h>
App::App()
{
}
void App::login_user()
{
	do {
		string email, password;
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
}
void App::main_menu()
{
	int ok1 = 1;
	while (ok1)
	{
		cout << "----MENU----\n" << endl;
		cout << "1. Add deposit" << endl;
		cout << "2. Print deposits" << endl;
		cout << "3. Select deposit" << endl;
		cout << "4. Delete deposit" << endl;
		cout << "5. Exit\n" << endl;
		cout << "Option: ";
		int option;
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
			if (deposit.get_name() == "" || deposit.get_address() == "" || deposit.get_file_name() == "")
			{
				system("pause");
				system("cls");
				break;
			}
			deposit.get_products();

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
				cout << "6. Save data" << endl;
				cout << "7. Return to main menu" << endl;

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
					Inventory::add_product(name, price, quantity, deposit.products);
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
					Product::delete_product(name, deposit.products);
					system("pause");
					system("cls");
					break;
				}
				case 3:
				{
					Inventory::print_inventory(deposit.products);
					system("pause");
					system("cls");
					break;
				}
				case 4:
				{
					Inventory::check_stock(deposit.products);
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
							Product::editing_the_product_price(name, new_price, deposit.products);
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
							Product::editing_the_product_quantity(name, new_quantity, deposit.products);
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
					deposit.save_data();
					cout << "The data was saved successfuly\n" << endl;
					Sleep(3000);
					system("cls");
				}
				case 7:
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
			ok1 = 0;
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
}
void App::run_app()
{
	login_user();
	main_menu();
}