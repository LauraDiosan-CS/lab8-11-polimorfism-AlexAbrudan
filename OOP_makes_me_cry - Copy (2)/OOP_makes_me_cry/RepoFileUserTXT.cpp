#include "RepoFileUserTXT.h"

#include <fstream>

using namespace std;


RepoFileUserTXT::RepoFileUserTXT() : RepoFileUser() {}
RepoFileUserTXT::RepoFileUserTXT(string file_name) : RepoFileUser(file_name) {}
RepoFileUserTXT::~RepoFileUserTXT() {}

void RepoFileUserTXT::load()
{
	string line;
	ifstream f(RepoFileUser::file_name);
	while (std::getline(f, line))
	{
		this->empty_repo();
		User u(line, ' ');
		RepoUser::users.push_back(u);
	}
	f.close();
}

void RepoFileUserTXT::save()
{
	ofstream f(RepoFileUser::file_name);
	for (User u : this->get_all())
	{
		if (this->find(u) ==-1)
			f << u.toString() << endl;
	}
}