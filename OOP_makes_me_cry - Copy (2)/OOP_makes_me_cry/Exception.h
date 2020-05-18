#pragma once

#include <stdexcept>

using namespace std;

class Exception : public runtime_error
{
private:
	string msg;
public:
	Exception(string msg);
	string what();
};

