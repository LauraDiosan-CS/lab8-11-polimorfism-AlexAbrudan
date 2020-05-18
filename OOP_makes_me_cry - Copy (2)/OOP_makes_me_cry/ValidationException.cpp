#include "ValidationException.h"


ValidationException::ValidationException(string msg) : runtime_error(msg)
{
	this->msg = msg;
}

string ValidationException::what()
{
	return this->msg;
}

