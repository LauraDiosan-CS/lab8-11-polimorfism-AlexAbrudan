#pragma once
#include "RepoFileUser.h"


class RepoFileUserTXT : public RepoFileUser
{
public:
	RepoFileUserTXT();
	RepoFileUserTXT(string file_name);
	~RepoFileUserTXT();

	void load();
	void save();
};

