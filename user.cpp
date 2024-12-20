#include "user.h"
#include <fstream>
#include <sstream>
#include <iostream>

User::User(string name, string first_name, string email, string password)
{
	this->name = name;
	this->first_name = first_name;
	this->email = email;
	this->password = password;
}
map<string, string> User::get_user(string email, string password)
{
	map<string, string> user;

	user["name"] = "";
	user["first_name"] = "";
	user["email"] = "";
	user["password"] = "";

	ifstream fisier("user.csv");

	if (!fisier.is_open())
	{
		cout << "Nu s-a putut deschide fisierul" << endl;

		return user;
	}

	string linie;

	getline(fisier, linie);
	while (getline(fisier, linie))
	{
		stringstream ss(linie);

		getline(ss, user["name"], ',');
		getline(ss, user["first_name"], ',');
		getline(ss, user["email"], ',');
		getline(ss, user["password"], ',');

		if (user["email"] == email && user["password"] == password)
		{
			return user;
		}
	}

	return user;
}

string User::get_name()
{
	return this->name;
}

string User::get_first_name()
{
	return this->first_name;
}

string User::get_email()
{
	return this->email;
}