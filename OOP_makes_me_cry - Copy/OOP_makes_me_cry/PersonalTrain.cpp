#include "PersonalTrain.h"
#include "Utils.h"


PersonalTrain::PersonalTrain() :Train()
{
	this->seat_number = -1;
}

PersonalTrain::PersonalTrain(int seat_number, string model_name, string producer_name, int cart_no, int av_cart_no, int res_cart_no) : Train(model_name, producer_name, cart_no, av_cart_no, res_cart_no)
{
	this->seat_number = seat_number;
}

PersonalTrain::PersonalTrain(const PersonalTrain& t) : Train(t)
{
	this->seat_number = t.seat_number;
}

PersonalTrain::~PersonalTrain()
{
	this->seat_number = -1;
}

int PersonalTrain::get_seat_number()
{
	return this->seat_number;
}

void PersonalTrain::set_seat_number(int new_seat_number)
{
	this->seat_number = new_seat_number;
}

string PersonalTrain::toString()
{
	string pt = "PT ";
	return pt + this->model_name + " " + this->producer_name + " " + to_string(this->cart_no) + " " + to_string(this->seat_number) + " " + to_string(this->av_cart_no) + " " + to_string(this->res_cart_no);
}

string PersonalTrain::toStringDelim(char delim)
{
	string pt = "PT";
	return pt + delim + this->model_name + delim + this->producer_name + delim + to_string(this->cart_no) + delim + to_string(this->seat_number) + delim + to_string(this->av_cart_no) + delim + to_string(this->res_cart_no);
}

PersonalTrain& PersonalTrain::operator=(const PersonalTrain& t)
{
	this->set_model_name(t.model_name);
	this->set_producer_name(t.producer_name);
	this->set_cart_no(t.cart_no);
	this->set_seat_number(t.seat_number);
	this->set_av_cart_no(t.av_cart_no);
	this->set_res_cart_no(t.res_cart_no);
	return *this;
}

bool PersonalTrain::operator==(const PersonalTrain& t)
{
	return (this->model_name == t.model_name && this->producer_name == t.producer_name && this->seat_number == t.seat_number && this->cart_no == t.cart_no && this->av_cart_no == t.av_cart_no && this->res_cart_no == t.res_cart_no);
}

PersonalTrain::PersonalTrain(string input, char delim)
{
	vector <string> res = split_string(input, delim);
	this->model_name = res[0];
	this->producer_name = res[1];
	this->cart_no = stoi(res[2]);
	this->seat_number = stoi(res[3]);
	this->av_cart_no = stoi(res[4]);
	this->res_cart_no = stoi(res[5]);
}

Train* PersonalTrain::clone()
{
	return new PersonalTrain(this->seat_number, this->model_name, this->producer_name, this->cart_no, this->av_cart_no, this->res_cart_no);
}