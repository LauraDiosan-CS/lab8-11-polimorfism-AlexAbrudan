#include "RepoFileUserCSV.h"

#include <fstream>

using namespace std;


RepoFileUserCSV::RepoFileUserCSV() : RepoFileUser() {}
RepoFileUserCSV::RepoFileUserCSV(string file_name) : RepoFileUser(file_name) {}
RepoFileUserCSV::~RepoFileUserCSV() {}

void RepoFileUserCSV::load()
{
	string line;
	ifstream f(RepoFileUser::file_name);

	if (f.is_open())
	{
		while (std::getline(f, line))
		{
			this->empty_repo();
			User u(line, ',');
			RepoUser::users.push_back(u);
		}
	}
	f.close();
}

void RepoFileUserCSV::save()
{
	ofstream f(RepoFileUser::file_name);
	if (f.is_open())
	{
		for (User u : RepoUser::users)
			f << u.toStringDelim(',') << endl;
	}
	f.close();
}