#include "PersonalTrainValidator.h"
#include "PersonalTrain.h"

#include <typeinfo>


PersonalTrainValidator::PersonalTrainValidator() : TrainValidator() {}

int PersonalTrainValidator::validate(Train* t)
{
	Train* to_vaidate = (PersonalTrain*)t;
	int tip = 0;

	if (((PersonalTrain*)to_vaidate)->get_seat_number()<0 || ((TrainValidator*)this->validate(t)) !=0)
	{
		this->err++;
		this->msg += "Seat number must be positive. ";
	}
	return this->err;
}

PersonalTrainValidator::~PersonalTrainValidator() {}