#ifndef CHEFS_H
#define CHEFS_H

#include "Command.h"
#include "Mediator.h"

class Chefs {

private:
	Chefs* nextHandler;
	Mediator* mediator;

public:
	void prepareOrder(Command order);

	void setNext(Chefs next);
};

#endif
