#ifndef SAUCECHEF_H
#define SAUCECHEF_H

#include "Chefs.h"
#include "Command.h"
#include <iostream>

class SauceChef : public Chefs {


public:
  SauceChef(Mediator* mediator) : Chefs(mediator) {}
	void cook(std::string dish);
	void prepareOrder(Command* order) override;
	virtual ~SauceChef()=default;

};

#endif
