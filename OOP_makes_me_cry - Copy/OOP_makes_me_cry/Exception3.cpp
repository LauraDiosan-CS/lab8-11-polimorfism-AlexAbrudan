#include "Exception3.h"


Exception3::Exception3(string msg) : runtime_error(msg)
{
	this->msg = msg;
}

string Exception3::what()
{
	return this->msg;
}