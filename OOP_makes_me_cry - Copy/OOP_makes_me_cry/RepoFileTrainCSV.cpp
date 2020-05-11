#include "RepoFileTrainCSV.h"


RepoFileTrainCSV::RepoFileTrainCSV() : RepoFileTrain() {}
RepoFileTrainCSV::RepoFileTrainCSV(string file_name) : RepoFileTrain(file_name) {}
RepoFileTrainCSV::~RepoFileTrainCSV() {}

void RepoFileTrainCSV::load()
{
	string line;
	ifstream f(RepoFileTrain::file_name);

	if (f.is_open())
	{
		this->clear_repo();
		while (std::getline(f, line))
		{
			Train* el = NULL;
			if (line.substr(0, 2) == "FT")
			{
				line.erase(0, 3);
				el = new FreightTrain(line, ',');
				if (this->find(el) == -1)
				{
					RepoTrain::trains.push_back(el);
					this->sort_trains();
				}
			}
			else
				if (line.substr(0, 2) == "PT")
				{
					line.erase(0, 3);
					el = new PersonalTrain(line, ',');
					if (this->find(el) == -1)
					{
						RepoTrain::trains.push_back(el);
						this->sort_trains();
					}
				}
		}
	}
	
	f.close();
}

void RepoFileTrainCSV::save()
{
	ofstream f(RepoFileTrain::file_name);
	for (Train* t : RepoTrain::trains)
	{
		if (strcmp(typeid(*t).name(), "class FreightTrain") == 0)
			f << ((FreightTrain*)t)->toStringDelim(',') << endl;
		else
			if (strcmp(typeid(*t).name(), "class PersonalTrain") == 0)
				f << ((PersonalTrain*)t)->toStringDelim(',') << endl;
	}
}