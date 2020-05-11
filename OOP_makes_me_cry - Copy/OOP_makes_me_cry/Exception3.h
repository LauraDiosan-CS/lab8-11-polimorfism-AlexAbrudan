#pragma once

#include <stdexcept>

#include "Exception.h"

using namespace std;


class Exception3 : public runtime_error
{
private:
	string msg;
public:
	Exception3(string msg);
	string what();
};

