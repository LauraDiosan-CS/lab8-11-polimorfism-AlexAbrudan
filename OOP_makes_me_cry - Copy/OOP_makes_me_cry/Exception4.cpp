#include "Exception4.h"


Exception4::Exception4(string msg) : runtime_error(msg)
{
	this->msg = msg;
}

string Exception4::what()
{
	return this->msg;
}

