#pragma once

#include "Train.h"

class TrainValidator
{
protected:
	int err;
	string msg;

public:
	TrainValidator();
	virtual int validate(Train* t);
	string toString();
	~TrainValidator();
};

