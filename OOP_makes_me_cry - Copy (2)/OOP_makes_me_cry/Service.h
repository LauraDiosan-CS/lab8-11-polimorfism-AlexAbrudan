#pragma once

#include "User.h"
#include "Train.h"
#include "FreightTrain.h"
#include "PersonalTrain.h"

#include "RepoFileTrainCSV.h"
#include "RepoFileTrainTXT.h"

#include "RepoFileUserCSV.h"
#include "RepoFileUserTXT.h"

class Service
{
private:
	RepoTrain* repo_trains;
	RepoUser* repo_users;
public:
	Service();
	Service(RepoTrain* repo_t, RepoUser* repo_u);
	~Service();

	void add_train(Train* t);
	int update_train(Train* old, Train* up);
	int del_train(Train* t);
	vector<Train*> all_trains();

	bool login(string id, string pass);
	bool reg(string id, string pass); //basically add user

	vector <Train*> search_by_producer(string query);
	vector <Train*> search_by_cart_no(int cart_no);

	void update_da_booked_thingys(string model, int new_booked_num);

	void save_trains();
	void save_users();

	void load_trains();
	void load_users();

	int size();

	Train* get(int pos);

	int in_vector(int v[], int n, int val);
};

