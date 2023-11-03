#ifndef JUNIORCHEF_H
#define JUNIORCHEF_H

#include "Chefs.h"
#include "Command.h"

class JuniorChef : public Chefs {


public:
	JuniorChef(){}
	JuniorChef(Mediator* mediator) : Chefs(mediator) {}
	void cook(std::string dish);
	void prepareOrder(Command* order, Waiter* currWaiter) override;
	virtual ~JuniorChef()=default;

};

#endif
