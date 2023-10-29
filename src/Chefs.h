#ifndef CHEFS_H
#define CHEFS_H

#include "Command.h"
#include "Mediator.h"
#include <iostream>

class Chefs {
	protected:
		Chefs* nextHandler;
	
  public:
	  Mediator* mediator;
	  Chefs(Mediator* mediator) : mediator(mediator) {}
    virtual void cook(std::string dish) = 0;
		Chefs();
		virtual void prepareOrder(Command* order);
		void setNext(Chefs* next);

};

#endif
