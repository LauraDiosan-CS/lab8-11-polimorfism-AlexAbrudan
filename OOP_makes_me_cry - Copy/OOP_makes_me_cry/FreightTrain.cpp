#include "FreightTrain.h"

#include "Utils.h"

#include <algorithm>

using namespace std;


FreightTrain::FreightTrain() :Train()
{
	this->transp_load.clear();
}

FreightTrain::FreightTrain(string transp_load, string model_name, string producer_name, int cart_no, int av_cart_no, int res_cart_no) : Train(model_name, producer_name, cart_no, av_cart_no, res_cart_no)
{
	this->transp_load = transp_load;
}

FreightTrain::FreightTrain(const FreightTrain& t) : Train(t)
{
	this->transp_load = t.transp_load;
}

FreightTrain::~FreightTrain()
{
	this->transp_load.clear();
}

string FreightTrain::get_transp_load()
{
	return this->transp_load;
}

void FreightTrain::set_transp_load(string new_transp_load)
{
	this->transp_load = new_transp_load;
}

string FreightTrain::toString()
{
	string ft = "FT ";
	return ft + this->model_name + " " + this->producer_name + " " + to_string(this->cart_no) + " " + this->transp_load + " " + to_string(this->av_cart_no) + " " + to_string(this->res_cart_no);
}

string FreightTrain::toStringDelim(char delim)
{
	string ft = "FT";
	return ft + delim + this->model_name + delim + this->producer_name + delim + to_string(this->cart_no) + delim + this->transp_load + delim + to_string(this->av_cart_no) + delim + to_string(this->res_cart_no);
}

FreightTrain& FreightTrain::operator=(const FreightTrain& t)
{
	this->set_model_name(t.model_name);
	this->set_producer_name(t.producer_name);
	this->set_cart_no(t.cart_no);
	this->set_transp_load(t.transp_load);
	this->set_av_cart_no(t.av_cart_no);
	this->set_res_cart_no(t.res_cart_no);
	return *this;
}

bool FreightTrain::operator==(const FreightTrain& t)
{
	return (this->model_name == t.model_name && this->producer_name == t.producer_name && this->transp_load == t.transp_load && this->cart_no == t.cart_no && this->av_cart_no == t.av_cart_no && this->res_cart_no == t.res_cart_no);
}

FreightTrain::FreightTrain(string input, char delim)
{
	vector <string> res = split_string(input, delim);
	this->model_name = res[0];
	this->producer_name = res[1];
	this->cart_no = stoi(res[2]);
	this->transp_load = res[3];
	this->av_cart_no = stoi(res[4]);
	this->res_cart_no = stoi(res[5]);
}

Train* FreightTrain::clone()
{
	return new FreightTrain(this->transp_load, this->model_name, this->producer_name, this->cart_no, this->av_cart_no, this->res_cart_no);

}