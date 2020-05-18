#include "RepoFileTrainCSV.h"
#include "TrainValidator.h"


RepoFileTrainCSV::RepoFileTrainCSV() : RepoFileTrain() {}
RepoFileTrainCSV::RepoFileTrainCSV(string file_name) : RepoFileTrain(file_name) {}
RepoFileTrainCSV::~RepoFileTrainCSV() {}

void RepoFileTrainCSV::load()
{
	TrainValidator* val = new TrainValidator();
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
				RepoTrain::trains.push_back(el);
			}
			else
				if (line.substr(0, 2) == "PT")
				{
					line.erase(0, 3);
					el = new PersonalTrain(line, ',');
					RepoTrain::trains.push_back(el);
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