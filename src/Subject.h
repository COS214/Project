#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "Observer.h"


class Subject {

private:
	std::vector<Observer> ObserverList;
	Observer* observer;

public:
	bool attach(int* Observer);

	bool detach(int* Observer);

	void notify();
};

#endif
