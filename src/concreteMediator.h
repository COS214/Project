#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include <string>

#include "Mediator.h"
#include "Chefs.h"

using namespace std;

class concreteMediator : Mediator {

public:
	Chefs* chefs;

	string orderStatus();

	void orderPosition();
};

#endif
