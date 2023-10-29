#ifndef HEADCHEF_H
#define HEADCHEF_H

#include "Chefs.h"
#include "Command.h"

class HeadChef : Chefs {


public:
	void prepareOrder(Command order);
	HeadChef(Mediator* mediator) : Chefs(mediator) {}
	void cook(std::string dish);
};

#endif
