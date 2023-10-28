#ifndef CHEFS_H
#define CHEFS_H

#include "Command.h"
#include "Mediator.h"
#include <iostream>

class Chefs {
	protected:
		Chefs* nextHandler;

	private:
		Mediator* mediator;

	public:
		Chefs();
		virtual void prepareOrder(Command* order);
		void setNext(Chefs* next);
};

#endif
