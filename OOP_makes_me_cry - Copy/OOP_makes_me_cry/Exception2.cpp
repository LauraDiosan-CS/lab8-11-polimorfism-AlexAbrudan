#include "Exception2.h"


Exception2::Exception2(string msg) : runtime_error(msg)
{
	this->msg = msg;
}

string Exception2::what()
{
	return this->msg;
}