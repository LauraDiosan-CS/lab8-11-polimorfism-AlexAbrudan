#include "RepoFileUser.h"


RepoFileUser::RepoFileUser() :RepoUser() {}
RepoFileUser::RepoFileUser(string file_name)
{
	this->file_name = file_name;
}
RepoFileUser::~RepoFileUser() {}
