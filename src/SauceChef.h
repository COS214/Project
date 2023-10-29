#ifndef SAUCECHEF_H
#define SAUCECHEF_H

#include "Chefs.h"
#include "Command.h"
#include <iostream>

class SauceChef : Chefs {
public:
	void prepareOrder(Command order);
	SauceChef(Mediator* mediator) : Chefs(mediator) {}
	void cook(std::string dish);
};

#endif
