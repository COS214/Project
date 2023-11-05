#ifndef SAUCECHEF_H
#define SAUCECHEF_H

#include "Chefs.h"
#include "Command.h"
#include <iostream>

class SauceChef : public Chefs {


public:
	SauceChef();
  	SauceChef(Mediator* mediator) : Chefs(mediator) {}
	void cook(std::string dish);
	void prepareOrder(Command* order, Waiter* currWaiter, int cookStrategy) override;
	virtual ~SauceChef()=default;

	bool isSauce(string item);

};

#endif
