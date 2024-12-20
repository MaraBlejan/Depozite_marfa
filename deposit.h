#pragma once
#include <string>
#include <vector>
#include "product.h"

using namespace std;

class Deposit
{
public:
	Deposit(string name, string address);
	string  get_name();
	string get_address();
	static void add_deposit(string name, string address);
	static  Deposit  select_deposit(string name);
	static void delete_deposit(string name);
	static void print_deposits();
private:
	string name;
	string address;
};
