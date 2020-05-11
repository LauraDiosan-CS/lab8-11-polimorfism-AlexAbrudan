#include "Train.h"
#include "Exception.h"


Train::Train()
{
	this->producer_name.clear();
	this->model_name.clear();
	this->av_cart_no = -1;
	this->res_cart_no = -1;
	this->cart_no = -1;
}

Train::Train(string model_name, string producer_name, int cart_no, int av_cart_no, int res_cart_no)
{
	this->model_name = model_name;
	this->producer_name = producer_name;
	this->cart_no = cart_no;
	this->av_cart_no = av_cart_no;
	this->res_cart_no = res_cart_no;
}

Train::Train(const Train& t)
{
	this->model_name = t.model_name;
	this->producer_name = t.producer_name;
	this->cart_no = t.cart_no;
	this->av_cart_no = t.av_cart_no;
	this->res_cart_no = t.res_cart_no;
}

Train::~Train()
{
	this->producer_name.clear();
	this->model_name.clear();
	this->av_cart_no = -1;
	this->res_cart_no = -1;
	this->cart_no = -1;
}

string Train::get_model_name()
{
	return this->model_name;
}

string Train::get_producer_name()
{
	return this->producer_name;
}

int Train::get_cart_no()
{
	return this->cart_no;
}

int Train::get_av_cart_no()
{
	return this->av_cart_no;
}

int Train::get_res_cart_no()
{
	return this->res_cart_no;
}

void Train::set_model_name(string new_model_name)
{
	this->model_name = new_model_name;
}

void Train::set_producer_name(string new_producer_name)
{
	this->producer_name = new_producer_name;
}

void Train::set_cart_no(int new_cart_no)
{
	this->cart_no = new_cart_no;
}

void Train::set_av_cart_no(int new_av_cart_no)
{
	this->av_cart_no = new_av_cart_no;
	this->res_cart_no = this->cart_no - new_av_cart_no;
}

void Train::set_res_cart_no(int new_res_cart_no)
{
	this->res_cart_no = new_res_cart_no;
	this->av_cart_no = this->cart_no - new_res_cart_no;
}

Train* Train::clone()
{
	return new Train(this->model_name, this->producer_name, this->cart_no, this->av_cart_no, this->res_cart_no);
}

Train& Train::operator=(const Train& t)
{
	this->model_name = t.model_name;
	this->producer_name = t.producer_name;
	this->cart_no = t.cart_no;
	this->av_cart_no = t.av_cart_no;
	this->res_cart_no = t.res_cart_no;
	return *this;
}

bool Train::operator==(const Train& t)
{
	return (this->model_name == t.model_name && this->producer_name == t.producer_name && this->cart_no == t.cart_no && this->av_cart_no == t.av_cart_no && this->res_cart_no == t.res_cart_no);
}

string Train::toString()
{
	return this->model_name + ' ' + this->producer_name + ' ' + to_string(this->cart_no) + ' ' + to_string(this->av_cart_no) + ' ' + to_string(this->res_cart_no);
}

string Train::toStringDelim(char delim)
{
	return this->model_name + delim + this->producer_name + delim + to_string(this->cart_no) + delim + to_string(this->av_cart_no) + delim + to_string(this->res_cart_no);
}

bool Train::operator>(const Train& t)
{
	return !(this->get_model_name() > t.model_name);
}