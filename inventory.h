#pragma once
#include <string>
#include <vector>
#include "product.h"

using namespace std;

class Inventory
{
public:
	static void add_product(string name, float price, int quantity, vector<Product>& products);
	static void print_inventory(vector<Product>& products);
	static void check_stock(vector<Product>& products);
};
