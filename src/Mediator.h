#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>

using namespace std;

class Chefs;

class Mediator {
public:
	virtual void notify(Chefs* sender, std::string event) = 0;
};

#endif
