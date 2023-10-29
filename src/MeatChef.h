#ifndef MEATCHEF_H
#define MEATCHEF_H

#include "Chefs.h"
#include "Command.h"
#include "CookStrategy.h"

class MeatChef : Chefs {

public:
	CookStrategy* cookStrategy;

	void prepareOrder(Command order);
	MeatChef(Mediator* mediator) : Chefs(mediator) {}
	void cook(std::string dish);
};

#endif
