#pragma once

#include <vector>
#include <algorithm>

#include "FreightTrain.h"
#include "PersonalTrain.h"

using namespace std;


class RepoTrain
{
protected:
	vector<Train*> trains;
public:
	RepoTrain();
	~RepoTrain();

	void add(Train* t);
	int update(Train* old, Train* up);
	int del(Train* t);
	int find(Train* t);
	Train* get(int pos);

	int size();
	vector<Train*> get_all();
	void clear_repo();
	bool compare(Train* t1, Train* t2);
	void sort_trains();
};

