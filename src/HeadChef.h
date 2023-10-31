#ifndef HEADCHEF_H
#define HEADCHEF_H

#include "Chefs.h"
#include "Command.h"

class HeadChef : public Chefs {


public:
	HeadChef(){}
	HeadChef(Mediator* mediator) : Chefs(mediator) {}
	void cook(std::string dish);
	void prepareOrder(Command* order) override;
	virtual ~HeadChef()=default;

};

#endif
