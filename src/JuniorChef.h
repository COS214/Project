#ifndef JUNIORCHEF_H
#define JUNIORCHEF_H

#include "Chefs.h"
#include "Command.h"

class JuniorChef : Chefs {


public:
	void prepareOrder(Command order);
	JuniorChef(Mediator* mediator) : Chefs(mediator) {}
	void cook(std::string dish);
};

#endif
