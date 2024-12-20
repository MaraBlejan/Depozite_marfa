#include "product.h"
#include <fstream>
#include <iostream>
#include<string>
#include"inventory.h"
#include<sstream>
#include <vector>
#include <cmath>
#include <iomanip>

Product::Product(string name, float price, int quantity)
{
	this->name = name;
	this->price = price;
	this->quantity = quantity;
}
string Product::get_name()
{
	return this->name;
}
float Product::get_price()
{
	return this->price;
}

int Product::get_quantity()
{
	return this->quantity;
}
void Product::set_price(float new_price)
{
	this->price = new_price;
}
void Product::set_quantity(int new_quantity)
{
	this->quantity = new_quantity;
}

void Product::editing_the_product_price(string deposit_name, string name, float new_price)
{
	vector<Product>products;
	bool found = false;
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
		string name_product;
		string price;
		string quantity;
		getline(file, line);

		while (getline(file, line))
		{
			stringstream ss(line);
			getline(ss, name_product, ',');
			getline(ss, price, ',');
			getline(ss, quantity, ',');

			Product product(name_product, stof(price), stoi(quantity));
			if (product.get_name() == name)
			{
				product.set_price(new_price);
				products.emplace_back(product);
				cout << "\nThe price was edited!\n" << endl;
				found = true;
			}
			else
			{
				products.emplace_back(product);
			}
		}
	}
	if (found == false)
	{
		cout << "\nProduct not found!\n" << endl;
	}
	else
	{
		ofstream file(deposit_name + ".csv");
		if (!file.is_open())
		{
			cout << "The file could not be opened!" << endl;
		}
		else
		{
			file << "name,price,quantity\n";
			for (Product product : products)
			{
				file << product.get_name() << "," << fixed << setprecision(2) << product.get_price() << ", " << product.get_quantity() << "\n";
			}
		}
	}
}
void Product::editing_the_product_quantity(string deposit_name, string name, int new_quantity)
{
	vector<Product>products;
	bool found = false;
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
		string name_product;
		string price;
		string quantity;
		getline(file, line);
		while (getline(file, line))
		{
			stringstream ss(line);
			getline(ss, name_product, ',');
			getline(ss, price, ',');
			getline(ss, quantity, ',');
			Product product(name_product, stof(price), stoi(quantity));
			if (product.get_name() == name)
			{
				product.set_quantity(new_quantity);
				products.emplace_back(product);
				found = true;
				cout << "The quantity was edited!\n" << endl;
			}
			else
			{
				products.emplace_back(product);
			}
		}
		if (found == false)
		{
			cout << "\nProduct not found!\n" << endl;
		}
		else
		{
			ofstream file(deposit_name + ".csv");
			if (!file.is_open())
			{
				cout << "The file could not be opened!" << endl;
			}
			else
			{
				file << "name,price,quantity\n";
				for (Product product : products)
				{
					file << product.get_name() << "," << fixed << setprecision(2) << product.get_price() << ", " << product.get_quantity() << "\n";
				}
			}
		}
	}
}
void Product::delete_product(string deposit_name, string name)
{
	vector<Product>products;
	bool found = false;
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
		string name_product;
		string price;
		string quantity;
		getline(file, line);
		while (getline(file, line))
		{
			stringstream ss(line);
			getline(ss, name_product, ',');
			getline(ss, price, ',');
			getline(ss, quantity, ',');
			Product product(name_product, stof(price), stoi(quantity));
			if (product.get_name() == name)
			{
				found = true;
			}
			else
			{
				products.emplace_back(product);
			}
		}
		if (found)
		{
			cout << "\nProduct deleted!\n" << endl;
		}
		else
		{
			cout << "\nProduct not found!\n" << endl;
		}
		ofstream file(deposit_name + ".csv");
		if (!file.is_open())
		{
			cout << "The file could not be opened!" << endl;
		}
		else
		{
			file << "name,price,quantity\n";
			for (Product product : products)
			{
				file << product.get_name() << "," << fixed << setprecision(2) << product.get_price() << ", " << product.get_quantity() << "\n";
			}
		}
	}
}