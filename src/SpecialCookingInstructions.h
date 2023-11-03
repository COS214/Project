#ifndef SPECIALCOOKINGINSTRUCTIONS_H
#define SPECIALCOOKINGINSTRUCTIONS_H

#include <iostream>
#include "DishDecorator.h"

class SpecialCookingInstructions : public DishDecorator {

private: 
	std::string instruction;

public:
	SpecialCookingInstructions();
	virtual void addSpecialInstruction(std::string instruction);
    double totalCost();
	
};


#endif
