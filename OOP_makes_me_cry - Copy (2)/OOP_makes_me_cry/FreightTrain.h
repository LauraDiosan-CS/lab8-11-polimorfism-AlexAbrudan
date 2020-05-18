#pragma once

#include <ostream>

#include "Train.h"

using namespace std;

class FreightTrain :public Train
{
private:
	string transp_load;
public:
	FreightTrain();
	FreightTrain(string transp_load, string model_name, string producer_name, int cart_no, int av_cart_no, int res_cart_no);
	FreightTrain(const FreightTrain& t);
	FreightTrain(string input, char delim);
	~FreightTrain();

	string get_transp_load();

	void set_transp_load(string new_transp_load);

	string toString();
	string toStringDelim(char delim);

	FreightTrain& operator=(const FreightTrain& t);
	bool operator==(const FreightTrain& t);

	Train* clone();
};

