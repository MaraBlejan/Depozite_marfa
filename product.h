#pragma once
#include <string>
#include <vector>

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
	static void editing_the_product_price(string name, float new_price, vector<Product>& products);
	static void editing_the_product_quantity(string name, int new_quantity, vector<Product>& products);
	static void delete_product(string name, vector<Product>& products);

private:
	string name;
	float price;
	int quantity;
};
