#ifndef ADDTODISH_H
#define ADDTODISH_H

#include <iostream>
#include "DishDecorator.h"

class AddToDish : public DishDecorator {

private:
	std::string ingredient;
	double costOfIngredient;

public:
	AddToDish(std::string name);
    void setIngredient(std::string ingredient);
    void setCostOfIngredient(double costOfIngredient);
	void addIngredient(std::string ingredient);
	double totalCost();
};


#endif
