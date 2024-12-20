#pragma once
#include <string>

using namespace std;

class Inventory
{
public:
	static void add_product(string deposit_name, string name, float price, int quantity);
	static void print_inventory(string deposit_name);
	static void check_stock(string deposit_name);
};
