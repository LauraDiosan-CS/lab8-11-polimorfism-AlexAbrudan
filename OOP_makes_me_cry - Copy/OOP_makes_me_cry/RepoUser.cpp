#include "RepoUser.h"
#include <algorithm>


RepoUser::RepoUser() { this->users.clear(); }
RepoUser::~RepoUser() { this->users.clear(); }

void RepoUser::add(User& u)
{
	this->users.push_back(u);
}

int RepoUser::find(User& u)
{
	vector<User>::iterator it = std::find(this->users.begin(), this->users.end(), u);
	if (it != this->users.end())
		return std::distance(this->users.begin(), it);
	else
		return -1;
}

int RepoUser::del(User& u)
{
	vector<User>::iterator it = std::find(this->users.begin(), this->users.end(), u);
	if (it != this->users.end())
	{
		this->users.erase(it);
		return 0;
	}
	return -1;
}

vector<User> RepoUser::get_all()
{
	return this->users;
}

void RepoUser::empty_repo()
{
	this->users.clear();
}