#pragma once

#include "RepoTrain.h"

class RepoFileTrain : public RepoTrain
{
protected:
	string file_name;
public:
	RepoFileTrain();
	RepoFileTrain(string file_name);
	~RepoFileTrain();

	virtual void load() = 0;
	virtual void save() = 0;
};

