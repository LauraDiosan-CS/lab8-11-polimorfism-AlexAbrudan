#include "RepoTrain.h"
#include "ValidationException.h"
#include "TrainValidator.h"
#include "PersonalTrainValidator.h"
#include <iostream>

using namespace std;

RepoTrain::RepoTrain() { this->trains.clear(); }
RepoTrain::~RepoTrain() { this->trains.clear(); }

void RepoTrain::add(Train* t)
{
	Train* blank = new Train();
	auto it = std::find(this->trains.begin(), this->trains.end(), blank);
	if (it != this->trains.end())
		this->trains.emplace(it, t);
	else
		this->trains.push_back(t);
}

int RepoTrain::update(Train* old, Train* up)
{
	int ok = this->find(old);
	TrainValidator* validator = new TrainValidator();
	if (validator->validate(up) == 0)
	{
		if (ok != -1)
		{
			//std::replace(this->trains.begin(), this->trains.end(), old, up);
			this->trains[ok - 1] = up;
			return 0;
		}
	}
	else
	{
		ValidationException t_invalid(validator->toString());
		throw t_invalid;
	}
	return -1;
}

int RepoTrain::del(Train* t)
{
	vector<Train*>::iterator it = std::find(this->trains.begin(), this->trains.end(), t);
	int ok = this->find(t);
	if (ok != -1)
	{
		this->trains.erase(this->trains.begin() + ok-1);
		return 0;
	}
	return -1;
}

int RepoTrain::find(Train* t)
{
	//auto it = std::find(this->trains.begin(), this->trains.end(), t);
	//if (it != this->trains.end())
		//return distance(this->trains.begin(), it);
	//else
		//return -1;
	int dist = 0;
	for (int i = 0; i < this->trains.size(); i++)
	{
		dist++;
		if (*this->trains[i] == *t)
			return dist;
	}
	return -1;
}

int RepoTrain::size()
{
	return this->trains.size();
}

vector<Train*> RepoTrain::get_all()
{
	return this->trains;
}

Train* RepoTrain::get(int pos)
{
	return this->trains[pos];
}

void RepoTrain::clear_repo()
{
	this->trains.clear();
}

bool RepoTrain::compare(Train* t1, Train* t2)
{
	return true;
}

void RepoTrain::sort_trains()
{
	
}