#pragma once
#include "Train.h"

class PersonalTrain :public Train
{
private:
	int seat_number;
public:
	PersonalTrain();
	PersonalTrain(int seat_number, string model_name, string producer_name, int cart_no, int av_cart_no, int res_cart_no);
	PersonalTrain(const PersonalTrain& t);
	PersonalTrain(string input, char delim);
	~PersonalTrain();

	int get_seat_number();

	void set_seat_number(int new_seat_number);

	string toString();
	string toStringDelim(char delim);

	PersonalTrain& operator=(const PersonalTrain& t);
	bool operator==(const PersonalTrain& t);

	Train* clone();
};

