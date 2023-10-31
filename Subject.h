#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>
#include <vector>
#include "Observer.h"

class Subject {

private:
	std::vector<Observer*> ObserverList;
	Observer* observer;

public:
	virtual bool attach(Observer* observer);
	virtual bool detach(Observer* observer);
	virtual void notify(std::string message);
};

#endif
