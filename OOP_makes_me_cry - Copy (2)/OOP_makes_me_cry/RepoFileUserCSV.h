#pragma once
#include "RepoFileUser.h"



class RepoFileUserCSV : public RepoFileUser
{
public:
	RepoFileUserCSV();
	RepoFileUserCSV(string file_name);
	~RepoFileUserCSV();

	void load();
	void save();
};

