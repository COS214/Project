#ifndef CHEFS_H
#define CHEFS_H

#include "Command.h"
#include "Mediator.h"
#include <iostream>

class Chefs {

private:
	Chefs* nextHandler;
	
public:
	Mediator* mediator;
	void prepareOrder(Command order);

	void setNext(Chefs* next);

	Chefs(Mediator* mediator) : mediator(mediator) {}
    virtual void cook(std::string dish) = 0;
};

#endif
