#pragma once
#include <string>
#include "Utils.h"

using namespace std;

class User
{
private:
	string id, pass;
public:
	User();
	User(string id, string pass);
	User(const User& u);
	User(string input, char delim);
	~User();

	string get_id();
	string get_pass();

	void set_id(string new_id);
	void set_pass(string new_pass);

	User& operator=(const User& u);
	bool operator==(const User& u);

	string toString();
	string toStringDelim(char delim);

	User* clone();
};

