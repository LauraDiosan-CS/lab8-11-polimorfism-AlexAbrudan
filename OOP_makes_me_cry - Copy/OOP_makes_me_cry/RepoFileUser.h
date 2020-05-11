#pragma once

#include "RepoUser.h"

class RepoFileUser : public RepoUser
{
protected:
	string file_name;
public:
	RepoFileUser();
	RepoFileUser(string file_name);
	~RepoFileUser();

	virtual void load() = 0;
	virtual void save() = 0;
};	

