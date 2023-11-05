#ifndef CHEFS_H
#define CHEFS_H

class Waiter;

#include "Command.h"
#include "Mediator.h"
#include "Order.h"
// #include "Waiter.h"
#include <iostream>
#include "Inventory.h"	

class Chefs {
	protected:
		Chefs* nextHandler;
	
  public:
		static Inventory* inventory;
	  Mediator* mediator;
	  Chefs(Mediator* mediator) : mediator(mediator) {}
    virtual void cook(std::string dish) = 0;
		Chefs();
		virtual void prepareOrder(Command* order, Waiter* currWaiter);
		void setNext(Chefs* next);
		void setMediator(Mediator* mediator);
};

#endif
