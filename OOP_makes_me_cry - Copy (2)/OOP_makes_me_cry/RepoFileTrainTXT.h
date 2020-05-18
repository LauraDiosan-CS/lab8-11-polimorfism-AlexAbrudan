#pragma once

#include <fstream>

#include "RepoFileTrain.h"


class RepoFileTrainTXT : public RepoFileTrain
{
public:
	RepoFileTrainTXT();
	RepoFileTrainTXT(string file_name);
	~RepoFileTrainTXT();

	void load();
	void save();
};

