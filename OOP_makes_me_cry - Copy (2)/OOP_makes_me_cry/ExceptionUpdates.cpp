#include "ExceptionUpdates.h"


ExceptionUpdates::ExceptionUpdates(string msg) : runtime_error(msg)
{
	this->msg = msg;
}

string ExceptionUpdates::what()
{
	return msg;
}