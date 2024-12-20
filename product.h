#pragma once
#include <string>

using namespace std;

class Product
{
public:
	Product(string name, float price, int quantity);
	string get_name();
	float get_price();
	int get_quantity();
	void set_price(float new_price);
	void set_quantity(int new_quantity);
	static void editing_the_product_price(string deposit_name, string name, float new_price);
	static void editing_the_product_quantity(string deposit_name, string name, int new_quantity);
	static void delete_product(string deposit_name, string name);
private:
	string name;
	float price;
	int quantity;
};
