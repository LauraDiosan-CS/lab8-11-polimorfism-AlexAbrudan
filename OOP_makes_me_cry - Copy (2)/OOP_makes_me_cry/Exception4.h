#pragma once

#include <stdexcept>

#include "Exception.h"

using namespace std;

class Exception4 : public runtime_error
{
private:
	string msg;
public:
	Exception4(string msg);
	string what();
};

