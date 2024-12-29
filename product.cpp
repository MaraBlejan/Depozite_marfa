#include "product.h"
#include <fstream>
#include <iostream>
#include<string>
#include"inventory.h"
#include<sstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "deposit.h"
#include<algorithm>

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

void Product::editing_the_product_price(string name, float new_price, vector<Product>& products)
{
	for (auto& product : products)
	{
		if (name == product.get_name())
		{
			product.set_price(new_price);
			cout << "Product edited!" << endl;

			return;
		}
	}
	cout << "Product not found!" << endl;
}

void Product::editing_the_product_quantity(string name, int new_quantity, vector<Product>& products)
{
	for (auto& product : products)
	{
		if (name == product.get_name())
		{
			product.set_quantity(new_quantity);
			cout << "Product edited!\n" << endl;

			return;
		}
	}
}

void Product::delete_product(string name, vector<Product>& products)
{
	int index = -1;
	for (int i = 0; i < products.size(); i++)
	{
		if (name == products[i].get_name())
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		cout << "The product was not found!" << endl;
	}
	else
	{
		products.erase(products.begin() + index);
		cout << "The product was deleted successuly! " << endl;
	}
}