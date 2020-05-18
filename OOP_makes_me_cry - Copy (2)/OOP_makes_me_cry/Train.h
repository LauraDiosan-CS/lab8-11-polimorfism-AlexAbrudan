#pragma once

#include <string>

using namespace std;

class Train
{
protected:
	string model_name;
	string producer_name;
	int cart_no, av_cart_no, res_cart_no;
public:
	Train();
	Train(string model_name, string producer_name, int cart_no, int av_cart_no, int res_cart_no);
	Train(const Train& t);
	~Train();

	string get_model_name();
	string get_producer_name();
	int get_cart_no();
	int get_av_cart_no();
	int get_res_cart_no();

	void set_model_name(string new_model_name);
	void set_producer_name(string new_producer_name);
	void set_cart_no(int new_cart_no);
	void set_av_cart_no(int new_av_cart_no);
	void set_res_cart_no(int new_res_cart_no);

	bool operator==(const Train& t);
	Train& operator=(const Train& t);
	bool operator>(const Train& t);


	string toString();
	string toStringDelim(char delim);

	virtual Train* clone();
};
