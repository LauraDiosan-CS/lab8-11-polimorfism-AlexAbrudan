#pragma once

#include "Service.h"

class UI
{
private:
	Service s;
public:
	UI();
	UI(Service& ss);
	~UI();

	void all_trains();
	void add_train();
	void update_train();
	void del_train();

	void menu();
	
	void search();
	void up_da_bookings();

	bool sign_up();
	bool sign_in();

	string color(int col, string text);

	bool log_or_reg();
	void f();
};

