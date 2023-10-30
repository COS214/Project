#ifndef SPECIALCOOKINGINSTRUCTIONS_H
#define SPECIALCOOKINGINSTRUCTIONS_H

#include <iostream>
#include "DishDecorator.h"

class SpecialCookingInstructions : DishDecorator {

private: 
	std::string instruction;

public:
	SpecialCookingInstructions(std::string name);
	void addSpecialInstruction(std::string instruction);
    double totalCost();
	
};


#endif
