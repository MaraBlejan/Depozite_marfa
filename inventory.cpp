#include "inventory.h"
#include <fstream>
#include <iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<iomanip>
#include"product.h"
void Inventory::add_product(string name, float price, int quantity, vector<Product>& products)
{
	products.emplace_back(Product(name, price, quantity));
}
void Inventory::print_inventory(vector<Product>& products)
{
	for (auto& product : products)
	{
		cout << product.get_name() << ", " << product.get_price() << ", " << product.get_quantity() << endl;
	}
}

void Inventory::check_stock(vector<Product>& products)
{
	for (auto& product : products)
	{
		if (product.get_quantity() < 10)
		{
			cout << "Need a restok for  " << product.get_name() << "!" << endl;
		}
		else if (product.get_quantity() > 10 || product.get_quantity() < 100)
		{
			cout << "No restok need for " << product.get_name() << "!" << endl;
		}
		else if (product.get_quantity() > 100)
		{
			cout << "No restok need  for " << product.get_name() << "!" << endl;
		}
	}
}