#pragma once
#include <stdexcept>

using namespace std;


class ExceptionUpdates : public runtime_error
{
private:
	string msg;
public:
	ExceptionUpdates(string msg);
	string what();
};

