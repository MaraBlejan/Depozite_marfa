#pragma once
#include <iostream>
class Menu
{
public:
	static void print_main_menu();
	static void print_select_deposit_menu();
	static void print_edit_product_menu();
	void add_deposit();
	void print_deposit();
	void delete_deposit();
	void exit_program();
	void add_product();
	void print_invrentory();
	void check_stock();
	void edit_product();
	void set_price();
	void set_quantity();
	void delete_product();
};
