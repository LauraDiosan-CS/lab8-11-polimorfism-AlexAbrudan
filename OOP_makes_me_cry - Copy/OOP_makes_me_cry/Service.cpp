#include "Service.h"
#include "Exception2.h"
#include "Exception3.h"


Service::Service() {}
Service::Service(RepoTrain* repo_t, RepoUser* repo_u)
{
	this->repo_trains = repo_t;
	this->repo_users = repo_u;
	this->load_users();
	this->load_trains();
}
Service::~Service() {}

void Service::add_train(Train* t)
{
	this->repo_trains->add(t);
	this->repo_trains->sort_trains();
}

int Service::update_train(Train* old, string model)
{
	//this->load_trains();
	//Train* up(old);
	//up->set_model_name(model);
	//int ok = this->repo_trains->update(old, up);
	vector<Train*> all_trains = this->all_trains();
	string models[500];
	int dim = 0;
	//for (int i = 0; i < all_trains.size(); i++) // se populeaza vectorul cu toate modelele
	//	models[dim++] = all_trains[i]->get_model_name();


	//if (ok == 0)
	//{
	//	return 0;
	//}
	//if (ok != 0)
	//{
	//	Exception3 UpdateException3("");
	//	throw UpdateException3;
	//}
	//if (old->get_model_name() == model)
	//{
	//	Exception2 UpdateException2("");
	//	throw UpdateException2;
	//}

	
	for (int i=0; i<all_trains.size(); i++)
		if (all_trains[i]->get_model_name() == model)
		{
			old->set_model_name(model);
			all_trains[i] = old;
		}
	for (int i = 0; i < dim; i++)
		if (models[i] != model)
		{
			Exception UpdateException1("");
			throw UpdateException1;
		}
	for (int i = 0; i < dim; i++)
		if (models[i] == model && old->get_model_name() != model)
		{
			Exception2 UpdateException2("");
			throw UpdateException2;
		}

}

int Service::del_train(Train* t)
{
	this->load_trains();
	int ok = this->repo_trains->del(t);
	if (ok == 0)
	{
		return 0;
	}
	return -1;
}

vector <Train*> Service::all_trains()
{
	this->load_trains();
	this->repo_trains->sort_trains();
	return this->repo_trains->get_all();
}

bool Service::login(string id, string pass)
{
	//this->load_users();
	User u(id, pass);
	int ok = this->repo_users->find(u);
	//this->save_users();
	if (ok != -1)
		return true;
	return false;
}

int Service::reg(string id, string pass)
{
	User u(id, pass);
	int ok = this->repo_users->find(u);
	if (ok == -1)
	{
		this->repo_users->add(u);
		return 0;
	}
	return -1;
}

vector <Train*> Service::search_by_producer(string query)
{
	vector <Train*> res;
	vector <Train*> all = this->all_trains();

	for (Train* t : all)
		if (t->get_producer_name() == query)
			res.push_back(t);
	return res;
}

vector <Train*> Service::search_by_cart_no(int cart_no)
{
	vector <Train*> res;
	vector <Train*> all = this->all_trains();

	for (Train* t : all)
		if (t->get_cart_no() == cart_no)
			res.push_back(t);
	return res;
}

void Service::update_da_booked_thingys(string model, int new_booked_num)
{
	vector <Train*> all = this->all_trains();

	for (Train* t : all)
		if (t->get_model_name() == model && 0 <= new_booked_num && new_booked_num <= t->get_cart_no())
			t->set_res_cart_no(new_booked_num);
	this->save_trains();
	
}

void Service::save_trains()
{
	//if (strcmp(typeid(*this->repo_trains).name(), "class RepoFileTrainCSV") == 0)
		((RepoFileTrainCSV*)this->repo_trains)->save();
	//else
		//if (strcmp(typeid(*this->repo_trains).name(), "class RepoFileTrainTXT") == 0)
			((RepoFileTrainTXT*)this->repo_trains)->save();
}

void Service::save_users()
{
	//if (strcmp(typeid(*this->repo_users).name(), "class RepoFileUserCSV") == 0)
		((RepoFileUserCSV*)this->repo_users)->save();
	//else
		//if (strcmp(typeid(*this->repo_users).name(), "class RepoFileUserTXT") == 0)
			((RepoFileUserTXT*)this->repo_users)->save();
}

void Service::load_trains()
{
	//if (strcmp(typeid(*this->repo_trains).name(), "class RepoFileTrainCSV") == 0)
		((RepoFileTrainCSV*)this->repo_trains)->load();
	//else
		//if (strcmp(typeid(*this->repo_trains).name(), "class RepoFileTrainTXT") == 0)
			((RepoFileTrainTXT*)this->repo_trains)->load();
}

void Service::load_users()
{
	((RepoFileUserCSV*)this->repo_users)->load();
	((RepoFileUserTXT*)this->repo_users)->load();
}

Train* Service::get(int pos)
{
	return this->repo_trains->get(pos);
}

int Service::size()
{
	return this->repo_trains->size();
}