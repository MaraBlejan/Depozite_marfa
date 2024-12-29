#include "deposit.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>

Deposit::Deposit(string name, string address, string file)
{
	this->name = name;
	this->address = address;
	this->file = file;
}

string Deposit::get_name()
{
	return this->name;
}
string Deposit::get_address()
{
	return this->address;
}

void Deposit::add_deposit(string name, string address)
{
	ofstream file("deposit.csv", ios::app);

	if (!file.is_open())
	{
		cout << "The file could not be opened!" << endl;
	}
	else
	{
		string file_name = name;
		for (int i = 0; i < file_name.size(); i++)
		{
			if (file_name[i] == ' ')
			{
				file_name[i] = '_';
			}
		}
		file_name = file_name + ".csv";
		file << name + "," + address + "," + file_name + "\n";

		ofstream deposit_file(file_name);
		if (!deposit_file.is_open())
		{
			cout << "The file could not be opened!" << endl;
			return;
		}
		deposit_file << "name,price,quantity\n";
		cout << "\nThe deposit was added!\n" << endl;
	}
}

Deposit Deposit::select_deposit(string name)
{
	ifstream file("deposit.csv");

	if (!file.is_open())
	{
		cout << "\nThe file could not be opened!\n" << endl;
		return Deposit("", "", "");
	}

	string line;
	string name_deposit;
	string address_deposit;
	string file_name;

	getline(file, line);

	while (getline(file, line))
	{
		stringstream ss(line);

		getline(ss, name_deposit, ',');
		getline(ss, address_deposit, ',');
		getline(ss, file_name, ',');

		if (name_deposit == name)
		{
			cout << "\nThe deposit was found!\n" << endl;
			return Deposit(name_deposit, address_deposit, file_name);
		}
	}
	cout << "\nThe deposit was not found!\n" << endl;
	return Deposit("", "", "");
}

void Deposit::print_deposits()
{
	ifstream file("deposit.csv");

	if (!file.is_open())
	{
		cout << "The file could not be opened!" << endl;
		return;
	}
	string line;
	string deposit_name;
	string deposit_address;

	getline(file, line);
	cout << "----DEPOSITS----" << endl;
	cout << "\n";
	while (getline(file, line))
	{
		stringstream ss(line);

		getline(ss, deposit_name, ',');
		getline(ss, deposit_address, ',');

		cout << "The name of the deposit is: " << deposit_name << endl;
		cout << "The address of the deposit is: " << deposit_address << "\n" << endl;
	}
}
void Deposit::delete_deposit(string name)
{
	vector<Deposit>deposits;
	bool found = false;
	string file_to_delet;
	ifstream file("deposit.csv");
	if (!file.is_open())
	{
		cout << "The file could not be opened!" << endl;
	}
	else
	{
		string line;
		string name_deposit;
		string address_deposit;
		string file_name;
		getline(file, line);
		while (getline(file, line))
		{
			stringstream ss(line);
			getline(ss, name_deposit, ',');
			getline(ss, address_deposit, ',');
			getline(ss, file_name, ',');
			Deposit deposit(name_deposit, address_deposit, file_name);
			if (deposit.get_name() == name)
			{
				found = true;
			}
			else
			{
				deposits.emplace_back(deposit);
			}
		}
		if (found)
		{
			if (remove((file_name).c_str()) == 0)
			{
				cout << "The deposit was deleted!\n" << endl;
			}
			else
			{
				cout << "The deposit could not be deleted!\n" << endl;
			}
		}
		else
		{
			cout << "The deposit was not found!\n" << endl;
		}
		ofstream file("deposit.csv");
		if (!file.is_open())
		{
			cout << "The file could not be opened!" << endl;
		}
		else
		{
			file << "name,address,file\n";
			for (Deposit deposit : deposits)
			{
				file << deposit.get_name() << "," << deposit.get_address() << "," << deposit.get_file_name() << "\n";
			}
		}
	}
}
void Deposit::get_products()
{
	ifstream file(this->file);

	if (!file.is_open())
	{
		cout << "The file could not be opened!" << endl;
		return;
	}
	else
	{
		string line;
		string name;
		string price;
		string quantity;

		getline(file, line);
		while (getline(file, line))
		{
			stringstream ss(line);

			getline(ss, name, ',');
			getline(ss, price, ',');
			getline(ss, quantity, ',');
			this->products.emplace_back(Product(name, stof(price), stoi(quantity)));
		}
	}
}
string Deposit::get_file_name()
{
	return this->file;
}
void Deposit::save_data()
{
	ofstream file(this->file);
	if (!file.is_open())
	{
		cout << "The file cannot be opened!" << endl;
		return;
	}
	else
	{
		file << "name,price,quantity\n";
		for (auto& product : products)
		{
			file << product.get_name() << "," << product.get_price() << "," << product.get_quantity() << "\n";
		}
	}
}