#pragma once

#include <fstream>

#include "RepoFileTrain.h"

using namespace std;

class RepoFileTrainCSV : public RepoFileTrain
{
public:
	RepoFileTrainCSV();
	RepoFileTrainCSV(string file_name);
	~RepoFileTrainCSV();

	void load();
	void save();
};

