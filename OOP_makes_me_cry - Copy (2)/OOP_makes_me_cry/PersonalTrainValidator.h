#pragma once

#include "TrainValidator.h"

class PersonalTrainValidator : public TrainValidator
{
public:
	PersonalTrainValidator();
	int validate(Train* t);
	~PersonalTrainValidator();
};

