#pragma once
#include <stdexcept>

using namespace std;


class ValidationException : public runtime_error
{
private:
	string msg;
public:
	ValidationException();
	ValidationException(string msg);
	string what();
};

