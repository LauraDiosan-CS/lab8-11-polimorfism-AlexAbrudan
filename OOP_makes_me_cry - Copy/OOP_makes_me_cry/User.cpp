#include "User.h"


User::User()
{
	this->id.clear();
	this->pass.clear();
}

User::User(string id, string pass)
{
	this->id = id;
	this->pass = pass;
}

User::User(const User& u)
{
	this->id = u.id;
	this->pass = u.pass;
}

User::~User()
{
	this->id.clear();
	this->pass.clear();
}

string User::get_id()
{
	return this->id;
}

string User::get_pass()
{
	return this->pass;
}

void User::set_id(string new_id)
{
	this->id = new_id;
}

void User::set_pass(string new_pass)
{
	this->pass = new_pass;
}

User& User::operator=(const User& u)
{
	this->id = u.id;
	this->pass = u.pass;
	return *this;
}

bool User::operator==(const User& u)
{
	return (this->id == u.id && this->pass == u.pass);
}

string User::toString()
{
	return this->id + " " + this->pass;
}

string User::toStringDelim(char delim)
{
	return this->id + delim + this->pass;
}

User::User(string input, char delim)
{
	vector <string> u = split_string(input, delim);
	this->id = u[0];
	this->pass = u[1];
}

User* User::clone()
{
	return new User(this->id, this->pass);
}