#include "SpecialCookingInstructions.h"
#include <iostream>

SpecialCookingInstructions::SpecialCookingInstructions(std::string name):DishDecorator(name) {

};

void SpecialCookingInstructions::addSpecialInstruction(std::string instruction){
	this->instruction = instruction;
	std::cout << "Added " << instruction << " for dish preparation." << std::endl;
	// where does special instruction go to - who handles it?
};

double SpecialCookingInstructions::totalCost(){  
	return getCost();
};
