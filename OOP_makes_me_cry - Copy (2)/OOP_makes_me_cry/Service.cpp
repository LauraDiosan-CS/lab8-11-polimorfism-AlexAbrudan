#include "Service.h"
#include "ExceptionUpdates.h"

#include <algorithm>


Service::Service() {}
Service::Service(RepoTrain* repo_t, RepoUser* repo_u)
{
	this->repo_trains = repo_t;
	this->repo_users = repo_u;
	//this->load_users();
	//this->load_trains();
}
Service::~Service() {}

int Service::in_vector(int v[], int n, int val)
{
	for (int i = 0; i < n; i++)
		if (v[i] == val)
			return 0;
	return -1;
}

void Service::add_train(Train* t)
{
	this->repo_trains->add(t);
	/*Train* blank = new Train();
	vector <Train*> all = this->all_trains();

	int models[500];
	int dim = 0;
	int* max_model = 0;

	bool ok = false;

	

	if (all.empty())
		this->repo_trains->add(t);
	else
	{
		for (Train* tr : all)
			models[dim++] = stoi(tr->get_model_name());

		max_model = max_element(models, models + dim);
		if (this->in_vector(models, dim, stoi(t->get_model_name())) == 0)
		{
			this->repo_trains->add(blank);
			
			t->set_model_name(to_string(int(max_model) + 1));
		}
		else
			this->repo_trains->add(t);

	}*/

	/*

	

	for (int i = 0; i < dim; i++)
		if (models[i] == stoi(t->get_model_name()))
		{
			ok = true;
			this->repo_trains->add(NULL);
		}

	if (ok == false)
		this->repo_trains->add(t);
	else
	{
		t->set_model_name(to_string(int(max_model)+1));
		this->repo_trains->add(t);
	}*/
}

int Service::size()
{
	return this->repo_trains->size();
}

Train* Service::get(int pos)
{
	return this->repo_trains->get(pos);
}

int Service::update_train(Train* old, Train* up)
{
	this->load_trains();
	int ok = this->repo_trains->update(old, up);
	
	if (ok == 0)
	{
		return 0;
	}
	return -1;
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

bool Service::reg(string id, string pass)
{
	User u(id, pass);
	int ok = this->repo_users->find(u);
	if (ok == -1)
	{
		this->repo_users->add(u);
		return true;
	}
	return false;
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

	string models[500];
	int dim = 0;

	bool ok = false;

	for (Train* t : all)
		models[dim++] = t->get_model_name();

	for (int i = 0; i < dim; i++)
		if (models[i] == model)
			ok = true;

	if (ok == false)
	{
		ExceptionUpdates no_model("The model you wish to update does not exist!");
		throw no_model;
	}

	for (Train* t : all)
		if (t->get_model_name() == model && 0 <= new_booked_num && new_booked_num <= t->get_cart_no())
			t->set_res_cart_no(new_booked_num + t->get_res_cart_no());
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