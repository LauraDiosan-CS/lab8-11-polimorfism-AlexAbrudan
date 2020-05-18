#pragma once
#include <vector>

#include "User.h"

using namespace std;

class RepoUser
{
protected:
	vector<User> users;
public:
	RepoUser();
	~RepoUser();

	void add(User& u);
	int del(User& u);
	int find(User& u);
	
	vector<User> get_all();
	void empty_repo();
};

