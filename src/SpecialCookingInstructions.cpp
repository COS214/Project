/**
 * @file SpecialCookingInstructions.cpp
 * @brief Contains the declaration of the SpecialCookingInstructions class functions.
 */

#include "SpecialCookingInstructions.h"
#include <iostream>

SpecialCookingInstructions::SpecialCookingInstructions() {

};

void SpecialCookingInstructions::addSpecialInstruction(std::string instruction){
	this->instruction = instruction;
	std::cout <<  instruction ;
	// where does special instruction go to - who handles it?
};

double SpecialCookingInstructions::totalCost(){  
	return getCost();
};
