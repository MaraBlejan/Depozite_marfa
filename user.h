#pragma once

#include <string>
#include <map>

using namespace std;

class User
{
public:
	static map<string, string> get_user(string email, string password);
	User(string name, string first_name, string email, string password);
	string get_name();
	string get_first_name();
	string get_email();

private:
	string name;
	string first_name;
	string email;
	string password;
};
