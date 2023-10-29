#ifndef MEATCHEF_H
#define MEATCHEF_H

#include "Chefs.h"
#include "Command.h"
#include "CookStrategy.h"

class MeatChef : public Chefs {

public:
	MeatChef(){}
	CookStrategy* cookStrategy;
	MeatChef(Mediator* mediator) : Chefs(mediator) {}
	void cook(std::string dish);
	void prepareOrder(Command* order) override;
	virtual ~MeatChef()=default;

};

#endif
