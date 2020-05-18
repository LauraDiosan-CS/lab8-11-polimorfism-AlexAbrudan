#pragma once

#include "Exception.h"

#include <stdexcept>

using namespace std;

class Exception2 : public runtime_error
{
private:
	string msg;
public:
	Exception2(string msg);
	string what();
};

