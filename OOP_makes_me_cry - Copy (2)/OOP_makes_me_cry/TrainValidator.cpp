#include "TrainValidator.h"
#include <typeinfo>

using namespace std;


TrainValidator::TrainValidator()
{
	this->err = 0;
}

int TrainValidator::validate(Train* t)
{
	this->err = 0;
	int tip = 0;

	if (t->get_cart_no() <0 || t->get_av_cart_no()<0 || t->get_res_cart_no()<0)
	{
		this->err++;
		this->msg += "Cart numbers must be positive. ";
	}
	return this->err;
}

string TrainValidator::toString()
{
	return this->msg;
}

TrainValidator::~TrainValidator() {}