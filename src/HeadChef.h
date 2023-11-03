#ifndef HEADCHEF_H
#define HEADCHEF_H



#include "Chefs.h"
#include "Command.h"
#include "Waiter.h"

class HeadChef : public Chefs {


public:
	HeadChef(){}
	HeadChef(Mediator* mediator) : Chefs(mediator) {}
	void cook(std::string dish);
	void prepareOrder(Command* order, Waiter* currWaiter) override;
	virtual ~HeadChef()=default;

};

#endif
