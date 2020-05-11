#include "RepoFileTrainTXT.h"


RepoFileTrainTXT::RepoFileTrainTXT() : RepoFileTrain() {}
RepoFileTrainTXT::RepoFileTrainTXT(string file_name) : RepoFileTrain(file_name) {}
RepoFileTrainTXT::~RepoFileTrainTXT() {}

void RepoFileTrainTXT::load()
{
	string line;
	ifstream f(RepoFileTrain::file_name);

	while (std::getline(f, line))
	{
		this->clear_repo();
		Train* el = NULL;
		if (line.substr(0, 2) == "FT")
		{
			line.erase(0, 3);
			el = new FreightTrain(line, ' ');
			RepoTrain::trains.push_back(el);
		}
		else
			if (line.substr(0, 2) == "PT")
			{
				line.erase(0, 3);
				el = new PersonalTrain(line, ' ');
				RepoTrain::trains.push_back(el);
			}
	}
	f.close();
}

void RepoFileTrainTXT::save()
{
	ofstream f(RepoFileTrain::file_name);
	for (Train* t : this->get_all())
	{
		if (strcmp(typeid(t).name(), "class FreightTrain") == 0)
			f << ((FreightTrain*)t)->toString()<<endl;
		else
			if (strcmp(typeid(t).name(), "class PersonalTrain") == 0)
				f << ((PersonalTrain*)t)->toString()<<endl;
	}
}