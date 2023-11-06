/**
 * @file SpecialCookingInstructions.h
 * @brief Contains the declaration of the SpecialCookingInstructions class.
 */

#ifndef SPECIALCOOKINGINSTRUCTIONS_H
#define SPECIALCOOKINGINSTRUCTIONS_H

#include <iostream>
#include "DishDecorator.h"

/**
 * @class SpecialCookingInstructions
 * @brief The SpecialCookingInstructions class represents a decorator for adding special cooking instructions to a dish.
 */
class SpecialCookingInstructions : public DishDecorator {

private: 
	std::string instruction;

public:
	/**
     * @brief Default constructor for the SpecialCookingInstructions class.
     */
	SpecialCookingInstructions();
     ~SpecialCookingInstructions()=default;

	/**
     * @brief Add a special cooking instruction to the dish.
     * @param instruction A string representing the special cooking instruction.
     */
	virtual void addSpecialInstruction(std::string instruction);

	/**
     * @brief Calculate the total cost of the dish with special instructions.
     * @return A double representing the total cost of the dish.
     */
    double totalCost();
	
};


#endif
