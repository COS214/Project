#ifndef VEGETABLECHEF_H
#define VEGETABLECHEF_H

#include "Chefs.h"
#include "Command.h"

class VegetableChef : public Chefs {


public:
	VegetableChef(){}
	VegetableChef(Mediator* mediator) : Chefs(mediator) {}
	void cook(std::string dish);
	void prepareOrder(Command* order) override;
	virtual ~VegetableChef()=default;
};

#endif
