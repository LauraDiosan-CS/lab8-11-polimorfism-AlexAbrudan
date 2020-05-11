#include "UI.h"
#include "Exception.h"
#include "Exception2.h"
#include "Exception3.h"
#include "Exception4.h"
#include <iostream>

using namespace std;

//
//UI::UI() {}
//UI::UI(Service& ss) { this->s = ss; }
//UI::~UI() {}
//
//void UI::all_trains()
//{
//	vector<Train*> all = this->s.all_trains();
//
//	for (Train* t : all)
//	{
//		if (strcmp(typeid(*t).name(), "class FreightTrain") == 0)
//			cout << ((FreightTrain*)t)->toString() << endl;
//		else
//			if (strcmp(typeid(*t).name(), "class PersonalTrain") == 0)
//				cout << ((PersonalTrain*)t)->toString() << endl;
//	}
//	cout << endl;
//}
//
//void UI::add_train()
//{
//	string model_name = "", producer_name = "", transp_load = "";
//	int cart_no=0, av_cart_no=0, res_cart_no=0, seat_number=0;
//	string type = "";
//
//	cout << "Enter model name: ";
//	cin >> model_name;
//	cout << "Enter producer's name: ";
//	cin >> producer_name;
//	cout << "Enter cart number: ";
//	cin >> cart_no;
//	cout << "Enter available cart number: ";
//	cin >> av_cart_no;
//	cout << "Enter booked cart number: ";
//	cin >> res_cart_no;
//	cout << endl;
//
//	cout << "Enter train type: ";
//	cin >> type;
//
//	if (type == "FT")
//	{
//		cout << "Enter transported load: ";
//		cin >> transp_load;
//		Train* t = new FreightTrain(transp_load, model_name, producer_name, cart_no, av_cart_no, res_cart_no);
//		this->s.add_train(t);
//	}
//	else
//		if (type == "PT")
//		{
//			cout << "Enter seat number: ";
//			cin >> seat_number;
//			Train* t = new PersonalTrain(seat_number, model_name, producer_name, cart_no, av_cart_no, res_cart_no);
//			this->s.add_train(t);
//			
//		}
//	if (av_cart_no + res_cart_no != cart_no)
//	{
//		Exception carts("Available cart number + booked cart number MUST be equal to the total cart number!");
//		throw carts;
//	}
//	if (av_cart_no != int(av_cart_no) || res_cart_no != int(res_cart_no) || cart_no != int(cart_no))
//	{
//		Exception3 integers("Cart numbers and seat numbers must be integers!");
//		throw integers;
//	}
//	this->s.save_trains();
//}
//
//void UI::update_train()
//{
//	this->s.load_trains();
//	string model_name, producer_name, transp_load;
//	int cart_no, av_cart_no, res_cart_no, seat_number;
//	string type = "";
//
//	string new_model_name, new_producer_name, new_transp_load;
//	int new_cart_no, new_av_cart_no, new_res_cart_no, new_seat_number;
//
//	int ok = -2;
//
//	cout << "Enter model name: ";
//	cin >> model_name;
//	cout << "Enter producer's name: ";
//	cin >> producer_name;
//	cout << "Enter cart number: ";
//	cin >> cart_no;
//	cout << "Enter available cart number: ";
//	cin >> av_cart_no;
//	cout << "Enter booked cart number: ";
//	cin >> res_cart_no;
//	cout << endl;
//
//	cout << "Enter train type: ";
//	cin >> type;
//
//	if (type == "FT")
//	{
//		cout << "Enter transported load: ";
//		cin >> transp_load;
//		Train* old = new FreightTrain(transp_load, model_name, producer_name, cart_no, av_cart_no, res_cart_no);
//		cout << endl;
//		cout << "Enter new model name: ";
//		cin >> new_model_name;
//		cout << "Enter new producer name: ";
//		cin >> new_producer_name;
//		cout << "Enter new cart number: ";
//		cin >> new_cart_no;
//		cout << "Enter new av cart number: ";
//		cin >> new_av_cart_no;
//		cout << "Enter new res cart number: ";
//		cin >> new_res_cart_no;
//		cout << "Enter new transported load: ";
//		cin >> new_transp_load;
//		Train* updated = new FreightTrain(new_transp_load, new_model_name, new_producer_name, new_cart_no, new_av_cart_no, new_res_cart_no);
//		ok =s.update_train(old, updated);
//		if (ok == 0)
//			cout << "Updated successfully!"<<endl;
//		if (new_av_cart_no + new_res_cart_no != new_cart_no)
//		{
//			Exception carts("Available cart number + booked cart number MUST be equal to the total cart number!");
//			throw carts;
//		}
//		if (ok == -1)
//		{
//			Exception2 inexistent("The given train does not exist!");
//			throw inexistent;
//		}
//		if (av_cart_no != int(av_cart_no) || res_cart_no != int(res_cart_no) || cart_no != int(cart_no))
//		{
//			Exception3 integers("Cart numbers and seat numbers must be integers!");
//			throw integers;
//		}
//		if (new_av_cart_no != int(new_av_cart_no) || new_res_cart_no != int(new_res_cart_no) || new_cart_no != int(new_cart_no))
//		{
//			Exception3 integers("Cart numbers and seat numbers must be integers!");
//			throw integers;
//		}
//	}
//	else
//		if (type == "PT")
//		{
//			cout << "Enter seat number: ";
//			cin >> seat_number;
//			Train* old = new PersonalTrain(seat_number, model_name, producer_name, cart_no, av_cart_no, res_cart_no);
//			cout << endl;
//			cout << "Enter new model name: ";
//			cin >> new_model_name;
//			cout << "Enter new producer name: ";
//			cin >> new_producer_name;
//			cout << "Enter new cart number: ";
//			cin >> new_cart_no;
//			cout << "Enter new av cart number: ";
//			cin >> new_av_cart_no;
//			cout << "Enter new res cart number: ";
//			cin >> new_res_cart_no;
//			cout << "Enter new seat number: ";
//			cin >> new_seat_number;
//			Train* updated = new PersonalTrain(new_seat_number, new_model_name, new_producer_name, new_cart_no, new_av_cart_no, new_res_cart_no);
//			ok = s.update_train(old, updated);
//			if (ok == 0)
//				cout << "Updated successfully!"<<endl;
//			if (new_av_cart_no + new_res_cart_no != new_cart_no)
//			{
//				Exception carts("Available cart number + booked cart number MUST be equal to the total cart number!");
//				throw carts;
//			}
//			if (ok == -1)
//			{
//				Exception2 inexistent("The given train does not exist!");
//				throw inexistent;
//			}
//			if (av_cart_no != int(av_cart_no) || res_cart_no != int(res_cart_no) || cart_no != int(cart_no))
//			{
//				Exception3 integers("Cart numbers and seat numbers must be integers!");
//				throw integers;
//			}
//			if (new_av_cart_no != int(new_av_cart_no) || new_res_cart_no != int(new_res_cart_no) || new_cart_no != int(new_cart_no))
//			{
//				Exception3 integers("Cart numbers and seat numbers must be integers!");
//				throw integers;
//			}
//		}
//	
//	this->s.save_trains();
//}
//
//void UI::del_train()
//{
//	this->s.load_trains();
//	string model_name, producer_name, transp_load;
//	int cart_no, av_cart_no, res_cart_no, seat_number;
//	string type = "";
//
//	cout << "Enter model name: ";
//	cin >> model_name;
//	cout << "Enter producer's name: ";
//	cin >> producer_name;
//	cout << "Enter cart number: ";
//	cin >> cart_no;
//	cout << "Enter available cart number: ";
//	cin >> av_cart_no;
//	cout << "Enter booked cart number: ";
//	cin >> res_cart_no;
//	cout << endl;
//
//	cout << "Enter train type: ";
//	cin >> type;
//
//	if (type == "FT")
//	{
//		cout << "Enter transported load: ";
//		cin >> transp_load;
//		Train* t = new FreightTrain(transp_load, model_name, producer_name, cart_no, av_cart_no, res_cart_no);
//		int ok = this->s.del_train(t);
//		if (ok == 0)
//			cout << "Deleted" << endl;
//		if (ok == -1)
//		{
//			Exception2 inexistent("The given train does not exist!");
//			throw inexistent;
//		}
//	}
//	else
//		if (type == "PT")
//		{
//			cout << "Enter seat number: ";
//			cin >> seat_number;
//			Train* t = new PersonalTrain(seat_number, model_name, producer_name, cart_no, av_cart_no, res_cart_no);
//			int ok = this->s.del_train(t);
//			
//			if (ok != -1)
//				cout << "Deleted!" << endl;
//			if (ok == -1)
//			{
//				Exception2 inexistent("The given train does not exist!");
//				throw inexistent;
//			}
//		}
//	this->s.save_trains();
//}
//
//void UI::search()
//{
//	char op = ' ';
//	string query = "";
//	int cart_num = 0;
//	system("CLS");
//	cout << "1. Search by producer. " << endl;
//	cout << "2. Search by cart number. " << endl;
//	cout << "Enter option: ";
//	cin >> op;
//	switch (op)
//	{
//		case '1':
//		{
//			cout << "Enter producer's name: ";
//			cin >> query;
//			vector <Train*> res = this->s.search_by_producer(query);
//			for (Train* t : res)
//			{
//				if (strcmp(typeid(*t).name(), "class FreightTrain") == 0)
//					cout << ((FreightTrain*)t)->toStringDelim(',') << endl;
//				else
//					if (strcmp(typeid(*t).name(), "class PersonalTrain") == 0)
//						cout << ((PersonalTrain*)t)->toStringDelim(',') << endl;
//			}
//			if (res.size() == 0)
//			{
//				Exception4 no_results("Your search did not return any results!");
//				throw no_results;
//			}
//			break;
//		}
//		case '2':
//		{
//			cout << "Enter cart number: ";
//			cin >> cart_num;
//			vector <Train*> res = this->s.search_by_cart_no(cart_num);
//			for (Train* t : res)
//			{
//				if (strcmp(typeid(*t).name(), "class FreightTrain") == 0)
//					cout << ((FreightTrain*)t)->toStringDelim(',') << endl;
//				else
//					if (strcmp(typeid(*t).name(), "class PersonalTrain") == 0)
//						cout << ((PersonalTrain*)t)->toStringDelim(',') << endl;
//			}
//			if (res.size() == 0)
//			{
//				Exception4 no_results("Your search did not return any results!");
//				throw no_results;
//			}
//			break;
//		}
//	}
//}
//
//void UI::up_da_bookings()
//{
//	string model = "";
//	int new_book_num = 0;
//	cout << "Enter the train model: ";
//	cin >> model;
//	cout << "Enter new number of booked thingys: ";
//	cin >> new_book_num;
//	this->s.update_da_booked_thingys(model, new_book_num);
//}
//
//bool UI::sign_up()
//{
//	string id, pass;
//	cout << "Enter id: ";
//	cin >> id;
//	cout << "Enter pass: ";
//	cin >> pass;
//	bool ok = this->s.reg(id, pass);
//	//this->s.save_users();
//	return ok;
//}
//
//bool UI::sign_in()
//{
//	string id, pass;
//	cout << "Enter id: ";
//	cin >> id;
//	cout << "Enter pass: ";
//	cin >> pass;
//	return this->s.login(id, pass);
//}
//
//bool UI::log_or_reg()
//{
//	char op = ' ';
//	bool ok = false;
//
//	while (true)
//	{
//		cout << "1. Login." << endl;
//		cout << "2. Registe." << endl;
//		cout << "Enter option: ";
//		cin >> op;
//		cout << endl;
//		switch (op)
//		{
//			case '1':
//			{
//				ok = this->sign_in();
//				if (ok == true)
//				{
//					system("CLS");
//					this->f();
//				}
//				else
//				{
//					cout << "nay" << endl;
//					system("CLS");
//				}
//				break;
//			}
//			case '2':
//			{
//				bool reg = this->sign_up();
//				if (reg == true)
//				{
//					system("CLS");
//					this->log_or_reg();
//				}
//				else
//				{
//					cout << "nay" << endl;
//					system("CLS");
//				}
//				break;
//			}
//			case 'x': {exit(0); break; }
//		}
//	}
//}
//
//void UI::menu()
//{
//	cout << "1. Add" << endl;
//	cout << "2. Show all. " << endl;
//	cout << "3. Update. " << endl;
//	cout << "4. Delete. " << endl;
//	cout << "5. Search. " << endl;
//	cout << "6. Whatever the fuck. " << endl;
//	cout << "x. Exit. " << endl;
//}
//
//void UI::f()
//{
//	char op = ' ';
//	try
//	{
//		while (true)
//		{
//			this->menu();
//			cout << "Enter option: ";
//			cin >> op;
//			cout << endl;
//			switch (op)
//			{
//			case '1': {this->add_train(); break; }
//			case '2': {this->all_trains(); break; }
//			case '3': {this->update_train(); break; }
//			case '4': {this->del_train(); break; }
//			case'5': {this->search(); break; }
//			case '6': {this->up_da_bookings(); break; }
//			case 'x': {exit(0); break; }
//			}
//		}
//	}
//	catch(Exception& carts)
//	{
//		cout << carts.what() << endl << endl;;
//		this->f();
//	}
//	catch (Exception2& inexistent)
//	{
//		cout << inexistent.what() << endl << endl;
//		this->f();
//	}
//	catch (Exception3& integers)
//	{
//		cout << integers.what() << endl << endl;
//		this->f();
//	}
//	catch (Exception4& no_results)
//	{
//		cout << no_results.what() << endl << endl;
//		this->f();
//	}
//}