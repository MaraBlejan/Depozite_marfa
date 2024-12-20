#include "inventory.h"
#include <fstream>
#include <iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
void Inventory::add_product(string deposit_name, string name, float price, int quantity)
{
	for (int i = 0; i < deposit_name.size(); i++)
	{
		if (deposit_name[i] == ' ')
		{
			deposit_name[i] = '_';
		}
	}

	ofstream file(deposit_name + ".csv", ios::app);
	if (!file.is_open())
	{
		cout << "The file could not be opened!" << endl;
		return;
	}

	file << name << "," << fixed << setprecision(2) << price << ", " << quantity << "\n";
	cout << "\nThe product was added!\n" << endl;
}
void Inventory::print_inventory(string deposit_name)
{
	for (int i = 0; i < deposit_name.size(); i++)
	{
		if (deposit_name[i] == ' ')
		{
			deposit_name[i] = '_';
		}
	}
	ifstream file(deposit_name + ".csv");
	if (!file.is_open())
	{
		cout << "The file could not be opened!" << endl;
	}
	else
	{
		string line;
		string name;
		string price;
		string quantity;
		getline(file, line);

		cout << "----PRODUCTS----\n" << endl;
		while (getline(file, line))
		{
			stringstream ss(line);
			getline(ss, name, ',');
			getline(ss, price, ',');
			getline(ss, quantity, ',');
			cout << name << " " << price << " " << quantity << endl;
		}
	}
	cout << "\n";
}
void Inventory::check_stock(string deposit_name)
{
	for (int i = 0; i < deposit_name.size(); i++)
	{
		if (deposit_name[i] == ' ')
		{
			deposit_name[i] = '_';
		}
	}
	ifstream file(deposit_name + ".csv");
	if (!file.is_open())
	{
		cout << "The file could not be opened!" << endl;
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
			if (stoi(quantity) <= 10)
			{
				cout << "Minimum stock for " << name << "! " << endl << "The quantity of " << name << " in the deposit is:" << quantity << "\n" << endl;
			}
			else
			{
				cout << "No restock needed for " << name << "!" << endl << "The quantity of " << name << " in the deposit is:" << quantity << "\n" << endl;
			}
		}
	}
	cout << endl;
}